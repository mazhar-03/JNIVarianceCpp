#include "Main.h"
#include <cmath>

JNIEXPORT jdouble JNICALL Java_Main_variance
        (JNIEnv *env, jobject obj, jdoubleArray jArr) {

    jsize length = env->GetArrayLength(jArr);
    jdouble *elements = env->GetDoubleArrayElements(jArr, 0);

    double sumOfArr = 0;
    for (int i = 0; i < length; i++)
        sumOfArr += elements[i];

    // we gon subtract the mean value from every element of the given data set.
    // Then taking the power of that values and sum everyone then we divide it by length-1
    double meanVal = sumOfArr / length;

    double sumOfPoweredArr = 0;

    for (int i = 0; i < length; i++)
        sumOfPoweredArr += pow((elements[i] - meanVal), 2);

    env->ReleaseDoubleArrayElements(jArr, elements, 0);

    return sumOfPoweredArr / (length - 1);

}