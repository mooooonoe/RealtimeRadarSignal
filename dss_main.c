#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NChirp 128
#define NChan 4
#define NSample 256

void rectwin(double win[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        win[i] = 1.0;
    }
}

void fft(double data_real[], double data_imag[], int n) {
    int i, j, k, m, u, v, w;
    int l, ll, a;
    double ang, cosang, sinang, temp_real, temp_imag;

    for (l = 1; l <= n / 2; l = 2 * l) {
        ll = 2 * l;
        a = n / ll;
        for (j = 0; j < l; j++) {
            ang = j * 2 * 3.14 / ll;
            cosang = cos(ang);
            sinang = sin(ang);
            for (i = j; i < n; i += ll) {
                temp_real = cosang * data_real[i + l] - sinang * data_imag[i + l];
                temp_imag = sinang * data_real[i + l] + cosang * data_imag[i + l];
                data_real[i + l] = data_real[i] - temp_real;
                data_imag[i + l] = data_imag[i] - temp_imag;
                data_real[i] += temp_real;
                data_imag[i] += temp_imag;
            }
        }
    }

    // Bit reversal
    j = 0;
    for (i = 1; i < n - 1; i++) {
        k = n / 2;
        while (k <= j) {
            j -= k;
            k /= 2;
        }
        j += k;
        if (i < j) {
            temp_real = data_real[i];
            temp_imag = data_imag[i];
            data_real[i] = data_real[j];
            data_imag[i] = data_imag[j];
            data_real[j] = temp_real;
            data_imag[j] = temp_imag;
        }
    }
}


int main() {
    FILE* file;
    float real_part[128];
    float imag_part[128];

    file = fopen("frameComplex.txt", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    for (int i = 0; i < 128; i++) {
        float real, imag;
        fscanf(file, "%f+%f", &real, &imag);
        real_part[i] = real;
        imag_part[i] = imag;
    }

    fclose(file);

    printf("실수부:\n");
    for (int i = 0; i < 128; i++) {
        printf("%.4f\t", real_part[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }

    printf("\n허수부:\n");
    for (int i = 0; i < 128; i++) {
        printf("%.4f\t", imag_part[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }

    // FFT Range Profile
    float radarCubeData_demo[NChirp][NChan][NSample] = { 0 };
    double win[NChirp * NChan * NSample];
    rectwin(win, NChirp * NChan * NSample);

    for (int chirpIdx = 0; chirpIdx < NChirp; chirpIdx++) {
        for (int chIdx = 0; chIdx < NChan; chIdx++) {
            printf("chirpIdx: %d, chIdx: %d\n", chirpIdx, chIdx); // 디버깅 문구 추가
            // Prepare input data for FFT
            double data_real[NSample];
            double data_imag[NSample];
            for (int i = 0; i < NSample; i++) {
                int index = chirpIdx * NChan * NSample + chIdx * NSample + i;
                data_real[i] = real_part[index] * win[i];
                data_imag[i] = imag_part[index] * win[i];
            }

            // Perform FFT
            fft(data_real, data_imag, NSample);

            // Copy the result to radarCubeData_demo
            for (int i = 0; i < NSample; i++) {
                radarCubeData_demo[chirpIdx][chIdx][i] = (float)data_real[i];
                printf("%f ", data_real[i]);
            }
            printf("\n");
        }
    }


    return 0;
}