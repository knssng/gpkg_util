//***********************************************************************************************************
// Record Count for GPKG File
// (c)AISIN 2021/11/28
//***********************************************************************************************************

//
// include
//
#include "ogrsf_frmts.h"
#include <string>
#include <iostream>


//
// main
//
int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Usage: count_gpkg_record.exe [arg1]" << std::endl;
        std::cerr << "  arg1: gpkg file path" << std::endl;
        std::cerr << std::endl;
        exit(1);
    }

    std::string file_bin  = argv[0];
    std::string gpkg_file = argv[1];

    
    GDALAllRegister();

    GDALDatasetUniquePtr poDS(GDALDataset::Open(gpkg_file.c_str(), GDAL_OF_VECTOR));
    if (poDS == nullptr)
    {
        std::cout << "+++ERROR Open failed." << std::endl;
        std::cout << "file = " << gpkg_file.c_str() << std::endl;
        exit(1);
    }

    for (auto poLayer : poDS->GetLayers())
    {
        // std::cout << poLayer->GetDescription() << std::endl;
        std::cout << "file  = " << gpkg_file.c_str() << std::endl;
        std::cout << "Layer = " << poLayer->GetName() << std::endl;
        std::cout << "count = " << poLayer->GetFeatureCount() << " (record)" << std::endl;

        /*
        for (const auto& poFeature : *poLayer)
        {

            for (const auto& oField : *poFeature)
            {
                std::cout << "  " << oField.GetType() << "/" << oField.GetName() << ":";

                if (oField.IsNull()) {
                    printf("(null)");
                }
                else{              
                    switch (oField.GetType())
                    {
                    case OFTInteger:
                        printf("%d,", oField.GetInteger());
                        break;
                    case OFTInteger64:
                        printf(CPL_FRMT_GIB ",", oField.GetInteger64());
                        break;
                    case OFTReal:
                        printf("%.3f,", oField.GetDouble());
                        break;
                    case OFTString:
                        printf("%s,", oField.GetString());
                        break;
                    default:
                        printf("%s,", oField.GetString());
                        break;
                    }
                }
                std::cout << std::endl;
            }

            const OGRGeometry* poGeometry = poFeature->GetGeometryRef();
            if (poGeometry != nullptr){

                std::cout << "  " << poGeometry->getGeometryName() << " ";

                const OGRPoint*        poPoint;
                const OGRLineString*   poLineString;

                switch (wkbFlatten(poGeometry->getGeometryType())) 
                {
                case wkbPoint :
                    poPoint = poGeometry->toPoint();
                    printf("%.10f,%.10f", poPoint->getX(), poPoint->getY());
                    break;
                case wkbLineString :
                    poLineString = poGeometry->toLineString();
                    for (const auto& oCoord : *poLineString) {
                        printf("%.12f %.12f %.1f,", oCoord.getX(), oCoord.getY(), oCoord.getZ());
                    }
                    break;
                default:
                    //
                    //
                    //
                    ;
                    break;
                }
            }
            else{
                std::cout << "  " << "No Geometry";
            }

            std::cout << std::endl;
        }
        */
    }

    return 0;
}