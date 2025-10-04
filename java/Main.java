public class Main
{
  public static final void
  main (final String[] arr) throws Exception
  {
    final CDotEnv env = new CDotEnv ();
    env.loadFromSrc ("""
    API_KEY=123456
    TOKEN=345
    """);

    final String apiKey = env.get ("API_KEY");
    final String token = env.get ("TOKEN");

    System.out.println (apiKey);
    System.out.println (token);
  }
}