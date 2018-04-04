
#include <stdlib.h>
#include <math.h>

float static_buffer[2156277];
float* dynamic_buffer = nullptr;

int meta_buf_0[] = {1978238,1971272,81,86,86,81};
int meta_buf_1[] = {1971272,888140,1,86,9,9,9,9,5,5,1,1,1,1,2,2};
int meta_buf_2[] = {888140,0,1990388,81,64,2150};
int meta_buf_3[] = {137600,1990388,2021492,64,81,64,81};
int meta_buf_4[] = {137664,137728,2021492,2005940,81,64,64,81};
int meta_buf_5[] = {2005940,1482194,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_6[] = {1482194,137792,2062964,81,64,576};
int meta_buf_7[] = {174656,2062964,2135540,64,64,64,81};
int meta_buf_8[] = {2135540,1622162,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_9[] = {1622162,174720,2052596,81,64,576};
int meta_buf_10[] = {211584,2052596,2052596,64,64,64,81};
int meta_buf_11[] = {2052596,1902098,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_12[] = {1902098,211648,2083700,81,64,576};
int meta_buf_13[] = {2083700,2021492,2021492,64,81,81,81,64};
int meta_buf_14[] = {248512,248576,2021492,2016308,81,64,64,81};
int meta_buf_15[] = {2016308,1202258,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_16[] = {1202258,248640,2037044,81,64,576};
int meta_buf_17[] = {285504,2037044,2109620,64,64,64,81};
int meta_buf_18[] = {2109620,1108946,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_19[] = {1108946,285568,1995572,81,64,576};
int meta_buf_20[] = {322432,1995572,1995572,64,64,64,81};
int meta_buf_21[] = {1995572,1762130,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_22[] = {1762130,322496,2125172,81,64,576};
int meta_buf_23[] = {2021492,2125172,2021492,81,64,81,64,81};
int meta_buf_24[] = {359424,359360,2021492,2104436,81,64,64,81};
int meta_buf_25[] = {2104436,1855442,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_26[] = {1855442,359488,2078516,81,64,576};
int meta_buf_27[] = {396352,2078516,2078516,64,64,64,81};
int meta_buf_28[] = {2078516,1248914,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_29[] = {1248914,396416,2114804,81,64,576};
int meta_buf_30[] = {433280,2114804,2114804,64,64,64,81};
int meta_buf_31[] = {2114804,1388882,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_32[] = {1388882,433344,2068148,81,64,576};
int meta_buf_33[] = {2068148,2021492,2021492,64,81,81,81,64};
int meta_buf_34[] = {470208,470272,2021492,2094068,81,64,64,81};
int meta_buf_35[] = {2094068,1668818,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_36[] = {1668818,470336,2031860,81,64,576};
int meta_buf_37[] = {507200,2031860,2130356,64,64,64,81};
int meta_buf_38[] = {2130356,1062290,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_39[] = {1062290,507264,2057780,81,64,576};
int meta_buf_40[] = {544128,2057780,2011124,64,64,64,81};
int meta_buf_41[] = {2011124,1528850,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_42[] = {1528850,544192,2140724,81,64,576};
int meta_buf_43[] = {2140724,2021492,2021492,64,81,81,81,64};
int meta_buf_44[] = {581120,581056,2021492,2151092,81,64,64,81};
int meta_buf_45[] = {2151092,1295570,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_46[] = {1295570,581184,2042228,81,64,576};
int meta_buf_47[] = {618048,2042228,2119988,64,64,64,81};
int meta_buf_48[] = {2119988,1342226,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_49[] = {1342226,618112,2099252,81,64,576};
int meta_buf_50[] = {654976,2099252,2099252,64,64,64,81};
int meta_buf_51[] = {2099252,1808786,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_52[] = {1808786,655040,2047412,81,64,576};
int meta_buf_53[] = {2047412,2021492,2073332,64,81,81,81,64};
int meta_buf_54[] = {2073332,691904,2156276,1,1,5184};
int meta_buf_55[] = {697088,2156276,2156276,1};
int meta_buf_56[] = {697089,697153,2021492,2000756,81,64,64,81};
int meta_buf_57[] = {2000756,1155602,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_58[] = {1155602,697217,2145908,81,64,576};
int meta_buf_59[] = {734081,2145908,2145908,64,64,64,81};
int meta_buf_60[] = {2145908,1575506,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_61[] = {1575506,734145,2088884,81,64,576};
int meta_buf_62[] = {771009,2088884,1985204,64,64,64,81};
int meta_buf_63[] = {1985204,1435538,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_64[] = {1435538,771073,2026676,81,64,576};
int meta_buf_65[] = {2026676,2021492,2026676,64,81,64,81,64};
int meta_buf_66[] = {2026676,1715474,1,64,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_67[] = {1715474,807937,1960013,81,139,576};
int meta_buf_68[] = {888001,1960013,1948754,139,81,139,81};
int* meta_buffers[] = {meta_buf_0,meta_buf_1,meta_buf_2,meta_buf_3,meta_buf_4,meta_buf_5,meta_buf_6,meta_buf_7,meta_buf_8,meta_buf_9,meta_buf_10,meta_buf_11,meta_buf_12,meta_buf_13,meta_buf_14,meta_buf_15,meta_buf_16,meta_buf_17,meta_buf_18,meta_buf_19,meta_buf_20,meta_buf_21,meta_buf_22,meta_buf_23,meta_buf_24,meta_buf_25,meta_buf_26,meta_buf_27,meta_buf_28,meta_buf_29,meta_buf_30,meta_buf_31,meta_buf_32,meta_buf_33,meta_buf_34,meta_buf_35,meta_buf_36,meta_buf_37,meta_buf_38,meta_buf_39,meta_buf_40,meta_buf_41,meta_buf_42,meta_buf_43,meta_buf_44,meta_buf_45,meta_buf_46,meta_buf_47,meta_buf_48,meta_buf_49,meta_buf_50,meta_buf_51,meta_buf_52,meta_buf_53,meta_buf_54,meta_buf_55,meta_buf_56,meta_buf_57,meta_buf_58,meta_buf_59,meta_buf_60,meta_buf_61,meta_buf_62,meta_buf_63,meta_buf_64,meta_buf_65,meta_buf_66,meta_buf_67,meta_buf_68};

extern "C" void init() {
    //static_buffer = (float*)malloc(2156277 * sizeof(float));
}

extern "C" float* get_static_buffer(void) {
    return static_buffer;
}

extern "C" float* allocate_dynamic_buffer(int count) {
    if (dynamic_buffer) {
        free(dynamic_buffer);
        dynamic_buffer = nullptr;
    }
    dynamic_buffer = (float*)malloc(count * sizeof(float));
    return dynamic_buffer;
}

extern "C" float* get_dynamic_buffer(void) {
    return dynamic_buffer;
}
extern "C" void set_placeholder_value(int kernel_order, int offset, int value) {
    meta_buffers[kernel_order][offset] = value;
}

void transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    float * v2 = (static_buffer + meta_buffer[1]);
    const int v3 = meta_buffer[2];
    const int v4 = meta_buffer[3];
    const int D0 = meta_buffer[4];
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(const int * meta_buffer)
{
    const float *im = (static_buffer + meta_buffer[0]);
    float *col = (static_buffer + meta_buffer[1]);

    const int N = meta_buffer[2];
    const int C1 = meta_buffer[3];
    const int H1 = meta_buffer[4];
    const int W1 = meta_buffer[5];
    const int H2 = meta_buffer[6];
    const int W2 = meta_buffer[7];
    const int KH = meta_buffer[8];
    const int KW = meta_buffer[9];
    const int DH = meta_buffer[10];
    const int DW = meta_buffer[11];
    const int SH = meta_buffer[12];
    const int SW = meta_buffer[13];
    const int PH = meta_buffer[14];
    const int PW = meta_buffer[15];

    for (int gid = 0; gid < N*H2*W2*KH*KW*C1; gid += 1) {
        const int c1 = gid % C1;
        const int kw = gid / C1 % KW;
        const int kh = gid / C1 / KW % KH;
        const int w2 = gid / C1 / KW / KH % W2;
        const int h2 = gid / C1 / KW / KH / W2 % H2;
        const int  n = gid / C1 / KW / KH / W2 / H2;

        const int h1 = h2 * SH - PH + kh * DH;
        const int w1 = w2 * SW - PW + kw * DW;

        col[gid] = (h1 < 0 || h1 >= H1 || w1 < 0 || w1 >= W1) ? 0 : im[((n*H1+h1)*W1+w1)*C1+c1];
    }
}


#ifndef INCLUDE_EIGEN
#define INCLUDE_EIGEN
#include <Eigen/Dense>
#endif

void tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(const int * meta_buffer)
{
    float *A = (static_buffer + meta_buffer[0]);
    float *B = (static_buffer + meta_buffer[1]);
    float *C = (static_buffer + meta_buffer[2]);

    Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> > a_mat(A, meta_buffer[3], meta_buffer[5]);
    Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor> > b_mat(B, meta_buffer[5], meta_buffer[4]);
    Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> > c_mat(C, meta_buffer[3], meta_buffer[4]);

    c_mat.noalias() = a_mat * b_mat;
}


void fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int D0 = meta_buffer[5];
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0*v5 + d1] = v9;
        }
    }
}


void fusedelementwise_a1f6b04630c46a30599bad0bd3f51f4f730aecbbaa414d4bc24389d8(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    float * v4 = (static_buffer + meta_buffer[3]);
    const int v5 = meta_buffer[4];
    const int v6 = meta_buffer[5];
    const int D0 = meta_buffer[6];
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v9 = v3[d0*v5 + d1];
            float v10;
            {
                v10 = v9 * v8;
            }
            float v11;
            {
                v11 = v10 + v7;
            }
            float v12;
            {
                v12 = v11 > 0 ? v11 : 0;
            }
            v4[d0 + d1*v6] = v12;
        }
    }
}


void fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int D0 = meta_buffer[5];
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


void elementwiseadd_ac3b0ad84c87c3fbee0be4b40495e45fd7dfb2c345c3a0d2b0a6f04a(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int v6 = meta_buffer[5];
    const int D0 = meta_buffer[6];
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v1[d0*v4 + d1];
            const float v8 = v2[d0 + d1*v5];
            float v9;
            {
                v9 = v8 + v7;
            }
            v3[d0 + d1*v6] = v9;
        }
    }
}


void elementwiseadd_ad3afebefcc7115e27de12d93792e115520f7d1cf46275ff86fc3fee(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int v6 = meta_buffer[5];
    const int D0 = meta_buffer[6];
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v1[d0*v4 + d1];
            const float v8 = v2[d0 + d1*v5];
            float v9;
            {
                v9 = v7 + v8;
            }
            v3[d0*v6 + d1] = v9;
        }
    }
}


void fusedelementwise_01efd7e87af9f9e78b234f196e568e8cf6c7e793a677bcaa0489d0e9(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    const float * v3 = (static_buffer + meta_buffer[2]);
    float * v4 = (static_buffer + meta_buffer[3]);
    const int v5 = meta_buffer[4];
    const int v6 = meta_buffer[5];
    const int D0 = meta_buffer[6];
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v7 = v1[d0];
        const float v8 = v2[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v9 = v3[d0*v5 + d1];
            float v10;
            {
                v10 = v9 * v7;
            }
            float v11;
            {
                v11 = v10 + v8;
            }
            float v12;
            {
                v12 = v11 > 0 ? v11 : 0;
            }
            v4[d0 + d1*v6] = v12;
        }
    }
}


void fusedelementwise_3670d2a67a0ee0879fb9cf6251fca97e281aa610fffa2d36890880d4(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int v6 = meta_buffer[5];
    const int D0 = meta_buffer[6];
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v1[d0*v4 + d1];
            const float v8 = v2[d0 + d1*v5];
            float v9;
            {
                v9 = v8 + v7;
            }
            float v10;
            {
                v10 = v9 > 0 ? v9 : 0;
            }
            v3[d0 + d1*v6] = v10;
        }
    }
}


void elementwiseadd_98450d361d3b8b06ad718e1e961bda61506f2baab3157c18aecbf897(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int D0 = meta_buffer[3];
    int d0;
    for (d0 = 0; d0 < D0; d0 += 1) {
        const float v4 = v1[d0];
        const float v5 = v2[d0];
        float v6;
        {
            v6 = v5 + v4;
        }
        v3[d0] = v6;
    }
}


void fusedelementwise_a1b9aeefc510417d3891c4faa25019005004ff23a295991b3974a8a2(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int v6 = meta_buffer[5];
    const int D0 = meta_buffer[6];
    const int D1 = meta_buffer[7];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v1[d0*v4 + d1];
            const float v8 = v2[d0 + d1*v5];
            float v9;
            {
                v9 = v8 + v7;
            }
            float v10;
            {
                v10 = v9 > 0 ? v9 : 0;
            }
            v3[d0*v6 + d1] = v10;
        }
    }
}


void elementwiseadd_a7a1bac0d1004f08225f89ef90716997e916fb65d62d759a6fac66b7(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int D0 = meta_buffer[5];
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            v3[d0*v5 + d1] = v8;
        }
    }
}

extern "C" void run() {
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_0);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_1);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_2);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_3);
fusedelementwise_a1f6b04630c46a30599bad0bd3f51f4f730aecbbaa414d4bc24389d8(meta_buf_4);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_5);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_6);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_7);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_8);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_9);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_10);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_11);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_12);
elementwiseadd_ac3b0ad84c87c3fbee0be4b40495e45fd7dfb2c345c3a0d2b0a6f04a(meta_buf_13);
fusedelementwise_a1f6b04630c46a30599bad0bd3f51f4f730aecbbaa414d4bc24389d8(meta_buf_14);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_15);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_16);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_17);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_18);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_19);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_20);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_21);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_22);
elementwiseadd_ad3afebefcc7115e27de12d93792e115520f7d1cf46275ff86fc3fee(meta_buf_23);
fusedelementwise_01efd7e87af9f9e78b234f196e568e8cf6c7e793a677bcaa0489d0e9(meta_buf_24);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_25);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_26);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_27);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_28);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_29);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_30);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_31);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_32);
elementwiseadd_ac3b0ad84c87c3fbee0be4b40495e45fd7dfb2c345c3a0d2b0a6f04a(meta_buf_33);
fusedelementwise_a1f6b04630c46a30599bad0bd3f51f4f730aecbbaa414d4bc24389d8(meta_buf_34);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_35);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_36);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_37);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_38);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_39);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_40);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_41);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_42);
elementwiseadd_ac3b0ad84c87c3fbee0be4b40495e45fd7dfb2c345c3a0d2b0a6f04a(meta_buf_43);
fusedelementwise_01efd7e87af9f9e78b234f196e568e8cf6c7e793a677bcaa0489d0e9(meta_buf_44);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_45);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_46);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_47);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_48);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_49);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_50);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_51);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_52);
fusedelementwise_3670d2a67a0ee0879fb9cf6251fca97e281aa610fffa2d36890880d4(meta_buf_53);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_54);
elementwiseadd_98450d361d3b8b06ad718e1e961bda61506f2baab3157c18aecbf897(meta_buf_55);
fusedelementwise_a1f6b04630c46a30599bad0bd3f51f4f730aecbbaa414d4bc24389d8(meta_buf_56);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_57);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_58);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_59);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_60);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_61);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_62);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_63);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_64);
fusedelementwise_a1b9aeefc510417d3891c4faa25019005004ff23a295991b3974a8a2(meta_buf_65);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_66);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_67);
elementwiseadd_a7a1bac0d1004f08225f89ef90716997e916fb65d62d759a6fac66b7(meta_buf_68);

}

