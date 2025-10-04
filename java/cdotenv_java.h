#ifndef __cdotenv_java_h__
#define __cdotenv_java_h__

#include <jni.h>

/*
 * Class:     CDotEnv
 * Method:    nativeLoadFromFile
 * Signature: (JLjava/lang/String;)B
 */
JNIEXPORT jbyte JNICALL Java_CDotEnv_nativeLoadFromFile (JNIEnv *, jclass,
                                                         jlong, jstring);

/*
 * Class:     CDotEnv
 * Method:    nativeLoadFromSrc
 * Signature: (JLjava/lang/String;)B
 */
JNIEXPORT jbyte JNICALL Java_CDotEnv_nativeLoadFromSrc (JNIEnv *, jclass,
                                                        jlong, jstring);

/*
 * Class:     CDotEnv
 * Method:    nativeGet
 * Signature: (J[Ljava/lang/String;Ljava/lang/String;)B
 */
JNIEXPORT jbyte JNICALL Java_CDotEnv_nativeGet (JNIEnv *, jclass, jlong,
                                                jobjectArray, jstring);

/*
 * Class:     CDotEnv
 * Method:    nativeClean
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_CDotEnv_nativeClean (JNIEnv *, jclass, jlong);

/*
 * Class:     CDotEnv
 * Method:    nativeStructSize
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_CDotEnv_nativeStructSize (JNIEnv *, jclass);

#endif
