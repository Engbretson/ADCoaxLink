EPICS_AUTO_ADDR_LIST=NO
export EPICS_AUTO_ADDR_LIST
#export EPICS_CA_MAX_ARRAY_BYTES=25165824


#EPICS_CA_ADDR_LIST=192.168.0.1
#export EPICS_CA_ADDR_LIST
EPICS_DISPLAY_PATH='
/local/epics/synApps_5_8/support/areaDetector-R3-1/ADCoaxLink/op/adl:/local/epics/synApps_5_8/support/areaDetector-R3-1/ADCore/ADApp/op/adl'

export EPICS_DISPLAY_PATH

# medm -x -macro "P=2BM_ADIMEC:, R=cam1:" CoaxlinkDetector.adl &

../../bin/linux-x86_64/coaxLinkApp st.cmd.linux

