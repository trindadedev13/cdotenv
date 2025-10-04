import java.io.File;
import java.lang.reflect.Field;
import java.nio.Buffer;
import java.nio.ByteBuffer;

public class CDotEnv
{
  static { System.loadLibrary ("cdotenv_java"); }

  private final long selfMemAddr;

  public CDotEnv () throws NoSuchFieldException, IllegalAccessException
  {
    selfMemAddr = unsafeCreate ();
  }

  public final void
  loadFromFile (final File file)
  {
    if (!file.exists ())
      throw new CDotEnvException ("Provided File not Exists.");
    byte res
        = CDotEnv.nativeLoadFromFile (selfMemAddr, file.getAbsolutePath ());
    if (res != 0)
      throw new CDotEnvException ("Something wrong loading file. Exit code: "
                                  + res);
  }

  public final void
  loadFromSrc (final String src)
  {
    byte res = CDotEnv.nativeLoadFromSrc (selfMemAddr, src);
    if (res != 0)
      throw new CDotEnvException ("Something wrong loading source. Exit code: "
                                  + res);
  }

  public final String
  get (final String name)
  {
    final String[] arr = new String[1];
    byte res = CDotEnv.nativeGet (selfMemAddr, arr, name);
    if (res != 0)
      throw new CDotEnvException ("Something wrong getting the key '" + name
                                  + "'. "
                                  + "Exit code: " + res);
    return arr[0];
  }

  private final static long
  unsafeCreate () throws NoSuchFieldException, IllegalAccessException
  {
    final ByteBuffer csb = ByteBuffer.allocateDirect (nativeStructSize ());
    final long addr = getAddress (csb);
    return addr;
  }

  /** get buffer addr with reflection */
  private final static long
  getAddress (final ByteBuffer buffer)
      throws NoSuchFieldException, IllegalAccessException
  {
    final Field addressField = Buffer.class.getDeclaredField ("address");
    addressField.setAccessible (true);
    return addressField.getLong (buffer);
  }

  private final static native byte nativeLoadFromFile (final long self,
                                                       final String filename);

  private final static native byte nativeLoadFromSrc (final long self,
                                                      final String src);

  private final static native byte nativeGet (final long self,
                                              final String[] out,
                                              final String name);

  private final static native void nativeClean (final long self);

  private final static native int nativeStructSize ();
}