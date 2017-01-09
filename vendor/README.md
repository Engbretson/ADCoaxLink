The Process_XML_Files.sh is used to generate the Area Detector ADL files, EDL files,template files, and does some quick-and-dirty generation of code that is simply included into the ADCoaxlink sources.

If some change is desired, it is generally faster to tweak the script, regenerate all the peices, and drop them in the corect locations instead of tediously digging through code. Does an inital read of all the paramters that seem useful; same coded also used for background value refreshes.  

Other Genicam based cameras parse this all out at run time, but the Euresys software suggests that it is . . . messy . . . to deal with the API at that level. The one they suggest using is very simple and easy, and works well when the code can be generated automagically.

The versions of the headers files between Linix and Windows do not seem to be in tortal sync. Please replace the files here with whatever versions match the ones that you have installed

