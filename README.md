# BuildMetaInfo
Optional module: Provides meta information about the build (build host, time, toolkit libs) for a quasar OPC-UA server.

This quasar optional module executes a python script (run on every build) which generates information describing the specifics of the build. THe generated information is available in C++ code via the following methods in file ```BuildMetaInfo.h```

```
std::string getBuildTime();
std::string getBuildHost();
std::string getToolkitLibs();
```
