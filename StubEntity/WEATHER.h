/**************************************************************************//**
* @file
*     モジュール名：業務データテーブル情報構造体
* <pre>
*     *********************************************************************
*     *     プログラム履歴      *     年月日       *      作成者氏名
*     *********************************************************************
*     *    作成  ＲＥＶ００１   *   １２０３２９   *      高原　幸輔
*     *********************************************************************
*
*    １  機能
*          業務データテーブル情報を定義する
*
*    ２  関数名一覧
*          省略
*
*    ３  更新履歴
*          REV001 : 新規作成
* </pre>
**//*NTT DATA*****************************************************************/
#ifndef _WEATHER_H_
#define _WEATHER_H_

#include <string>
#include <PBase>

class POINT {
public:
    int x;
    int y;
    int z;
};

namespace StubEntity {

class WEATHER : public ::Entity::AbstEntity {
public:
    static constexpr char ENTITY_NAME[] = "WEATHER";

    char  INFO_TYPE[ 1 + 1];
    int   FORECAST_TIME;
    int   ALT;
    char  ELEM_ID[ 1 + 1];
    int   AREA_LAT_NORTH;
    int   AREA_LAT_SOUTH;
    int   AREA_LONG_EAST;
    int   AREA_LONG_WEST;
    char  LATTICE_ID[ 1 + 1];
    char  LATTICE_GAP_EW[ 5 + 1];
    char  LATTICE_GAP_SN[ 5 + 1];
    char  SCAN_DIR_EW[ 1 + 1];
    char  SCAN_DIR_SN[ 1 + 1];
    int   SIZE;
    int   ACCURACY;
    char  UNIT[ 1 + 1];
    char  ENDIAN_ID[ 1 + 1];
    int   GRID_NUM;
    POINT DATA;
    ::Time::time  OBSERVED_TIME;
};

class WeatherIndexer : public ::Entity::ImplIndexer {
public:
    static constexpr char INDEXER_NAME[] = "WeatherIndexer";
    WeatherIndexer();
    ~WeatherIndexer();
    int compare(const ::Entity::AbstEntity&, const ::Entity::AbstEntity&) const;
    virtual const ::std::string getIndexerName() const;
};

extern WeatherIndexer* gWEATHERIndexer;

}   // end namespace StubEntity

#endif/* _WEATHER_H_ */

