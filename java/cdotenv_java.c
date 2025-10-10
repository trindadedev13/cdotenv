#include "cdotenv_java.h"

#include <jni.h>

#include "cdotenv.h"

JNIEXPORT jbyte JNICALL
Java_CDotEnv_nativeLoadFromFile (JNIEnv *env, jclass clazz, jlong jself,
                                 jstring jfilename)
{
  (void)clazz;
  struct cdotenv *self = (struct cdotenv *)jself;
  const char *filename = (*env)->GetStringUTFChars (env, jfilename, 0);
  int8_t status = cdotenv_load_from_file (self, filename);
  (*env)->ReleaseStringUTFChars (env, jfilename, filename);
  return (jbyte)status;
}

JNIEXPORT jbyte JNICALL
Java_CDotEnv_nativeLoadFromSrc (JNIEnv *env, jclass clazz, jlong jself,
                                jstring jsrc)
{
  (void)clazz;
  struct cdotenv *self = (struct cdotenv *)jself;
  const char *src = (*env)->GetStringUTFChars (env, jsrc, 0);
  int8_t status = cdotenv_load_from_src (self, src);
  (*env)->ReleaseStringUTFChars (env, jsrc, src);
  return (jbyte)status;
}

JNIEXPORT jbyte JNICALL
Java_CDotEnv_nativeGet (JNIEnv *env, jclass clazz, jlong jself,
                        jobjectArray jout, jstring jname)
{
  (void)clazz;
  struct cdotenv *self = (struct cdotenv *)jself;
  const char *name = (*env)->GetStringUTFChars (env, jname, 0);
  char *value = NULL;
  int8_t status = cdotenv_get (self, &value, name);
  if (status == 0 && value != NULL)
  {
    jstring jvalue = (*env)->NewStringUTF (env, value);
    (*env)->SetObjectArrayElement (env, jout, 0, jvalue);
  }
  (*env)->ReleaseStringUTFChars (env, jname, name);
  return (jbyte)status;
}

JNIEXPORT void JNICALL
Java_CDotEnv_nativeClean (JNIEnv *env, jclass clazz, jlong jself)
{
  (void)env;
  (void)clazz;
  struct cdotenv *self = (struct cdotenv *)jself;
  cdotenv_clean (self);
}

JNIEXPORT jint JNICALL
Java_CDotEnv_nativeStructSize (JNIEnv *env, jclass clazz)
{
  (void)env;
  (void)clazz;
  return sizeof (struct cdotenv);
}
