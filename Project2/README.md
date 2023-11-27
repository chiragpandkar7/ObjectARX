This exercise explains how to compile the AU2014 ObjectARX project and then load it into AutoCAD.

In Microsoft Visual Studio, on the menu bar, click Build  Build Solution. 1>Build succeeded.
Start AutoCAD .
In AutoCAD, on the ribbon, click Manage tab -> Applications panel -> Load Application. SD6174-L: Sparring with Autodesk® ObjectARX®—Round 2 Stepping into the Ring
In the Load/Unload Applications dialog box, and browse to the location of the compiled ARX file. Select AU2014.arx and click Load.
In the File Loading - Security Concern message box, click Load.
Click Close.
Press F2 to display the AutoCAD Text Window or expand the Command Line window. You should notice that the following messages have been displayed. Loading AU2014 project... AU2014.arx successfully loaded. The message ‘Loading AU2014 project...’ is displayed using the acutPrintf method in the acrxEntryPoint function when kInitAppMsg is handled. Once an ObjectARX application is loaded, you cannot recompile it until you unload the compiled output file. The following steps explain how to unload an ObjectARX application from AutoCAD.
In AutoCAD, on the ribbon, click Manage tab  Applications panel  Load Application.
In the Load/Unload Applications dialog box, under the Loaded Applications tab, select AU2014.arx and click Unload.
Click Close.
Press F2 to display the AutoCAD Text Window or expand the Command Line window. You should notice that the following messages have been displayed. Unloading AU2014 project... au2014.arx successfully unloaded. The message ‘Unloading AU2014 project...’ is displayed using the acutPrintf method in the acrxEntryPoint function when kUnloadAppMsg is handled.
