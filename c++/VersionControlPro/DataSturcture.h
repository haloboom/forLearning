typedef struct version{
  char* content;
  char* change;
  int versionID;
  //Date
  struct version* newVersion;
  struct version* oldVersion; 
}Ver,*pVer;

class VersionControl
{
  private Ver version;
  public VersionControl()
  {}
  public VersionControl(char* content)
  {
    if(content)
    {
      version.content = content;
    }
  }
  ~VersionControl()
  {}
};
