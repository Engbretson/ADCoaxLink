
mkdir inc
mkdir Db
mkdir opi
mkdir opi/adl

rm *.edl
rm *.template
rm *.adl
rm *.ui

rm inc/*.inc
rm Db/*template
rm opi/adl/*.adl

makeDbAndAdl3.py ./Adimec_Q12A180CXP_1_1_3.xml ./Adimec_Q12A180CXP_1_1_3 Remote
makeDbAndAdl3.py ./Euresys_Coaxlink_TLDataStream_6_2_4.xml ./Euresys_Coaxlink_TLDataStream_6_2_4 Stream
makeDbAndAdl3.py ./Euresys_Coaxlink_TLDevice_6_2_4.xml ./Euresys_Coaxlink_TLDevice_6_2_4 Device
makeDbAndAdl3.py ./Euresys_Coaxlink_TLInterface_6_2_4.xml ./Euresys_Coaxlink_TLInterface_6_2_4 Interface
makeDbAndAdl3.py ./Euresys_Coaxlink_TLSystem_6_2_4.xml ./Euresys_Coaxlink_TLSystem_6_2_4 System

