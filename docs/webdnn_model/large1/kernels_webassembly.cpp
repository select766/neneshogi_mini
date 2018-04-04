
#include <stdlib.h>
#include <math.h>

float static_buffer[10028661];
float* dynamic_buffer = nullptr;

int meta_buf_0[] = {10021694,10014728,81,86,86,81};
int meta_buf_1[] = {10014728,6645452,1,86,9,9,9,9,5,5,1,1,1,1,2,2};
int meta_buf_2[] = {6645452,0,9572306,81,192,2150};
int meta_buf_3[] = {412800,9572306,9914450,192,81,192,81};
int meta_buf_4[] = {412992,413184,9914450,9478994,81,192,192,81};
int meta_buf_5[] = {9478994,8639186,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_6[] = {8639186,413376,9727826,81,192,1728};
int meta_buf_7[] = {745152,9727826,9961106,192,192,192,81};
int meta_buf_8[] = {9961106,6819602,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_9[] = {6819602,745344,9790034,81,192,1728};
int meta_buf_10[] = {1077120,9790034,9790034,192,192,192,81};
int meta_buf_11[] = {9790034,8919122,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_12[] = {8919122,1077312,9805586,81,192,1728};
int meta_buf_13[] = {9805586,9914450,9914450,192,81,81,81,192};
int meta_buf_14[] = {1409088,1409280,9914450,9634514,81,192,192,81};
int meta_buf_15[] = {9634514,7379474,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_16[] = {7379474,1409472,9603410,81,192,1728};
int meta_buf_17[] = {1741248,9603410,9541202,192,192,192,81};
int meta_buf_18[] = {9541202,8359250,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_19[] = {8359250,1741440,9681170,81,192,1728};
int meta_buf_20[] = {2073216,9681170,9681170,192,192,192,81};
int meta_buf_21[] = {9681170,7239506,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_22[] = {7239506,2073408,9852242,81,192,1728};
int meta_buf_23[] = {9852242,9914450,9914450,192,81,81,81,192};
int meta_buf_24[] = {2405184,2405376,9914450,9556754,81,192,192,81};
int meta_buf_25[] = {9556754,6959570,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_26[] = {6959570,2405568,9712274,81,192,1728};
int meta_buf_27[] = {2737344,9712274,9712274,192,192,192,81};
int meta_buf_28[] = {9712274,7659410,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_29[] = {7659410,2737536,9587858,81,192,1728};
int meta_buf_30[] = {3069312,9587858,9587858,192,192,192,81};
int meta_buf_31[] = {9587858,7939346,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_32[] = {7939346,3069504,9696722,81,192,1728};
int meta_buf_33[] = {9696722,9914450,9914450,192,81,81,81,192};
int meta_buf_34[] = {3401280,3401472,9914450,9758930,81,192,192,81};
int meta_buf_35[] = {9758930,8499218,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_36[] = {8499218,3401664,9821138,81,192,1728};
int meta_buf_37[] = {3733440,9821138,9836690,192,192,192,81};
int meta_buf_38[] = {9836690,9059090,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_39[] = {9059090,3733632,9883346,81,192,1728};
int meta_buf_40[] = {4065408,9883346,9945554,192,192,192,81};
int meta_buf_41[] = {9945554,9339026,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_42[] = {9339026,4065600,9494546,81,192,1728};
int meta_buf_43[] = {9494546,9914450,9914450,192,81,81,81,192};
int meta_buf_44[] = {4397568,4397376,9914450,9525650,81,192,192,81};
int meta_buf_45[] = {9525650,7519442,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_46[] = {7519442,4397760,9510098,81,192,1728};
int meta_buf_47[] = {4729536,9510098,9510098,192,192,192,81};
int meta_buf_48[] = {9510098,7799378,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_49[] = {7799378,4729728,9650066,81,192,1728};
int meta_buf_50[] = {5061504,9650066,9665618,192,192,192,81};
int meta_buf_51[] = {9665618,8219282,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_52[] = {8219282,5061696,9743378,81,192,1728};
int meta_buf_53[] = {5393664,5393472,9914450,9774482,81,192,192,81};
int meta_buf_54[] = {9774482,8779154,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_55[] = {8779154,5393856,9618962,81,192,1728};
int meta_buf_56[] = {5725632,9618962,9618962,192,192,192,81};
int meta_buf_57[] = {9618962,9199058,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_58[] = {9199058,5725824,9930002,81,192,1728};
int meta_buf_59[] = {6057600,9930002,9976658,192,192,192,81};
int meta_buf_60[] = {9976658,7099538,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_61[] = {7099538,6057792,9898898,81,192,1728};
int meta_buf_62[] = {9743378,9914450,9867794,192,81,81,81,192};
int meta_buf_63[] = {9867794,6389568,10028660,1,1,15552};
int meta_buf_64[] = {6405120,10028660,10028660,1};
int meta_buf_65[] = {9898898,9914450,9898898,192,81,192,81,192};
int meta_buf_66[] = {9898898,8079314,1,192,9,9,9,9,3,3,1,1,1,1,1,1};
int meta_buf_67[] = {8079314,6405121,10003469,81,139,1728};
int meta_buf_68[] = {6645313,10003469,9992210,139,81,139,81};
int* meta_buffers[] = {meta_buf_0,meta_buf_1,meta_buf_2,meta_buf_3,meta_buf_4,meta_buf_5,meta_buf_6,meta_buf_7,meta_buf_8,meta_buf_9,meta_buf_10,meta_buf_11,meta_buf_12,meta_buf_13,meta_buf_14,meta_buf_15,meta_buf_16,meta_buf_17,meta_buf_18,meta_buf_19,meta_buf_20,meta_buf_21,meta_buf_22,meta_buf_23,meta_buf_24,meta_buf_25,meta_buf_26,meta_buf_27,meta_buf_28,meta_buf_29,meta_buf_30,meta_buf_31,meta_buf_32,meta_buf_33,meta_buf_34,meta_buf_35,meta_buf_36,meta_buf_37,meta_buf_38,meta_buf_39,meta_buf_40,meta_buf_41,meta_buf_42,meta_buf_43,meta_buf_44,meta_buf_45,meta_buf_46,meta_buf_47,meta_buf_48,meta_buf_49,meta_buf_50,meta_buf_51,meta_buf_52,meta_buf_53,meta_buf_54,meta_buf_55,meta_buf_56,meta_buf_57,meta_buf_58,meta_buf_59,meta_buf_60,meta_buf_61,meta_buf_62,meta_buf_63,meta_buf_64,meta_buf_65,meta_buf_66,meta_buf_67,meta_buf_68};

extern "C" void init() {
    //static_buffer = (float*)malloc(10028661 * sizeof(float));
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
elementwiseadd_ac3b0ad84c87c3fbee0be4b40495e45fd7dfb2c345c3a0d2b0a6f04a(meta_buf_23);
fusedelementwise_a1f6b04630c46a30599bad0bd3f51f4f730aecbbaa414d4bc24389d8(meta_buf_24);
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
fusedelementwise_01efd7e87af9f9e78b234f196e568e8cf6c7e793a677bcaa0489d0e9(meta_buf_53);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_54);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_55);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_56);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_57);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_58);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_59);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_60);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_61);
fusedelementwise_3670d2a67a0ee0879fb9cf6251fca97e281aa610fffa2d36890880d4(meta_buf_62);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_63);
elementwiseadd_98450d361d3b8b06ad718e1e961bda61506f2baab3157c18aecbf897(meta_buf_64);
fusedelementwise_a1b9aeefc510417d3891c4faa25019005004ff23a295991b3974a8a2(meta_buf_65);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_66);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_67);
elementwiseadd_a7a1bac0d1004f08225f89ef90716997e916fb65d62d759a6fac66b7(meta_buf_68);

}

