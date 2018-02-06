
#export EPICS_CA_MAX_ARRAY_BYTES=25165824


export EPICS_DISPLAY_PATH='/local/epics/synApps_5_8/support/areaDetector-R3-1/ADCoaxLink/coaxLinkApp/op/adl:/local/epics/synApps_5_8/support/areaDetector-R3-1/ADCore/ADApp/op/adl'

/APSshare/epics/extensions/bin/linux-x86_64/medm -x -macro "P=2BM_ADIMEC:, R=cam1:" CoaxlinkDetector.adl &

#/APSshare/epics/extensions/bin/linux-x86_64/medm -x -macro "P=2BM_ADIMEC:, R=raw1:" NDFileRaw.adl &
 
#../../bin/linux-x86_64/coaxLinkApp st.cmd.linux

