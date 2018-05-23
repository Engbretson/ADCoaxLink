
#export EPICS_CA_MAX_ARRAY_BYTES=25165824


export EPICS_DISPLAY_PATH='/local/epics/areaDetector-3-2/ADCoaxLink/coaxLinkApp/op/adl:/local/epics/areaDetector-3-2/ADCore-3-2/ADApp/op/adl'

/APSshare/epics/extensions/bin/linux-x86_64/medm -x -macro "P=2BM_ADIMEC:, R=cam1:" CoaxlinkDetector.adl &

#/APSshare/epics/extensions/bin/linux-x86_64/medm -x -macro "P=2BM_ADIMEC:, R=raw1:" NDFileRaw.adl &
 
#../../bin/linux-x86_64/coaxLinkApp st.cmd.linux

