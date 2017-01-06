
rm *.edl
rm *.template
rm *.adl
rm *.ui

makeDbAndAdl.py /home/beams/MENGBRET/test/Adimec_Q12A180CXP_1_1_3.xml /home/beams/MENGBRET/test/Adimec_Q12A180CXP_1_1_3 Remote
makeDbAndAdl.py /home/beams/MENGBRET/test/Euresys_Coaxlink_TLDataStream_6_1_1.xml /home/beams/MENGBRET/test/Euresys_Coaxlink_TLDataStream_6_1_1 Stream
makeDbAndAdl.py /home/beams/MENGBRET/test/Euresys_Coaxlink_TLDevice_6_1_1.xml /home/beams/MENGBRET/test/Euresys_Coaxlink_TLDevice_6_1_1 Device
makeDbAndAdl.py /home/beams/MENGBRET/test/Euresys_Coaxlink_TLInterface_6_1_1.xml /home/beams/MENGBRET/test/Euresys_Coaxlink_TLInterface_6_1_1 Interface
makeDbAndAdl.py /home/beams/MENGBRET/test/Euresys_Coaxlink_TLSystem_6_1_1.xml /home/beams/MENGBRET/test/Euresys_Coaxlink_TLSystem_6_1_1 System

for f in *features.adl
do
	/APSshare/caqtdm/caqtdm-4.0.0/caQtDM_Binaries/Adlui $f
done
