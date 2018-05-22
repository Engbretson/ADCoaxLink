
mkdir inc
mkdir Db
mkdir op
mkdir op/adl
mkdir op/ui


rm *.edl
rm *.template
rm *.adl
rm *.ui

rm inc/*.inc
rm Db/*template
rm op/adl/*.adl

./makeDbAndAdl3.py ./Adimec_Q12A180CXP_1_1_5.xml ./Adimec_Q12A180CXP_1_1_5 Remote
./makeDbAndAdl3.py ./Euresys_Coaxlink_TLDataStream_9_5_2.xml ./Euresys_Coaxlink_TLDataStream_9_5_2 Stream
./makeDbAndAdl3.py ./Euresys_Coaxlink_TLDevice_9_5_2.xml ./Euresys_Coaxlink_TLDevice_9_5_2 Device
./makeDbAndAdl3.py ./Euresys_Coaxlink_TLInterface_9_5_2.xml ./Euresys_Coaxlink_TLInterface_9_5_2 Interface
./makeDbAndAdl3.py ./Euresys_Coaxlink_TLSystem_9_5_2.xml ./Euresys_Coaxlink_TLSystem_9_5_2 System

for f in ./op/adl/*.adl
do
	/APSshare/caqtdm/caqtdmGIT/caQtDM_Binaries/adl2ui $f 
done

# This can all be automagic, but at the instant, need to make a small manual tweak to inc inc file
# with maor changes, the single template files needs to be recreated from all the peices

mv -f *.ui ./op/ui/

cp -f ./inc/*  ../../coaxLinkApp/coaxLinkSrc/
cp -f ./Db/*  ../../coaxLinkApp/Db/
cp -f -r ./op/*  ../../coaxLinkApp/op/
