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
#include <StubEntity/WEATHER.h>

namespace StubEntity {

using ::Entity::Column;

constexpr char WEATHER::ENTITY_NAME[];
constexpr char WeatherIndexer::INDEXER_NAME[];

WeatherIndexer::WeatherIndexer() {
}

WeatherIndexer::~WeatherIndexer() {
}

int WeatherIndexer::compare(const ::Entity::AbstEntity& obj1,
        const ::Entity::AbstEntity& obj2) const {
    const WEATHER& def1 = static_cast<const WEATHER&>(obj1);
    const WEATHER& def2 = static_cast<const WEATHER&>(obj2);
    return def1.FORECAST_TIME - def2.FORECAST_TIME;
}

const ::std::string WeatherIndexer::getIndexerName() const {
    return INDEXER_NAME;
}

/*--------1---------2---------3---------4---------5---------6---------7------*/
const ::Entity::EntityCache gWEATHER(
        WEATHER::ENTITY_NAME, { sizeof(WEATHER), {
    {"INFO_TYPE",      {Column::CHAR_ARRAY, 1, OFFSET(WEATHER, INFO_TYPE),      sizeof(WEATHER::INFO_TYPE)}},
    {"FORECAST_TIME",  {Column::INT32,      1, OFFSET(WEATHER, FORECAST_TIME),  sizeof(WEATHER::FORECAST_TIME)}},
    {"ALT",            {Column::INT32,      1, OFFSET(WEATHER, ALT),            sizeof(WEATHER::ALT)}},
    {"ELEM_ID",        {Column::CHAR_ARRAY, 1, OFFSET(WEATHER, ELEM_ID),        sizeof(WEATHER::ELEM_ID)}},
    {"AREA_LAT_NORTH", {Column::INT32,      0, OFFSET(WEATHER, AREA_LAT_NORTH), sizeof(WEATHER::AREA_LAT_NORTH)}},
    {"AREA_LAT_SOUTH", {Column::INT32,      0, OFFSET(WEATHER, AREA_LAT_SOUTH), sizeof(WEATHER::AREA_LAT_SOUTH)}},
    {"AREA_LONG_EAST", {Column::INT32,      0, OFFSET(WEATHER, AREA_LONG_EAST), sizeof(WEATHER::AREA_LONG_EAST)}},
    {"AREA_LONG_WEST", {Column::INT32,      0, OFFSET(WEATHER, AREA_LONG_WEST), sizeof(WEATHER::AREA_LONG_WEST)}},
    {"LATTICE_ID",     {Column::CHAR_ARRAY, 0, OFFSET(WEATHER, LATTICE_ID),     sizeof(WEATHER::LATTICE_ID)}},
    {"LATTICE_GAP_EW", {Column::CHAR_ARRAY, 0, OFFSET(WEATHER, LATTICE_GAP_EW), sizeof(WEATHER::LATTICE_GAP_EW)}},
    {"LATTICE_GAP_SN", {Column::CHAR_ARRAY, 0, OFFSET(WEATHER, LATTICE_GAP_SN), sizeof(WEATHER::LATTICE_GAP_SN)}},
    {"SCAN_DIR_EW",    {Column::CHAR_ARRAY, 0, OFFSET(WEATHER, SCAN_DIR_EW),    sizeof(WEATHER::SCAN_DIR_EW)}},
    {"SCAN_DIR_SN",    {Column::CHAR_ARRAY, 0, OFFSET(WEATHER, SCAN_DIR_SN),    sizeof(WEATHER::SCAN_DIR_SN)}},
    {"SIZE",           {Column::INT32,      0, OFFSET(WEATHER, SIZE),           sizeof(WEATHER::SIZE)}},
    {"ACCURACY",       {Column::INT32,      0, OFFSET(WEATHER, ACCURACY),       sizeof(WEATHER::ACCURACY)}},
    {"UNIT",           {Column::CHAR_ARRAY, 0, OFFSET(WEATHER, UNIT),           sizeof(WEATHER::UNIT)}},
    {"ENDIAN_ID",      {Column::CHAR_ARRAY, 0, OFFSET(WEATHER, ENDIAN_ID),      sizeof(WEATHER::ENDIAN_ID)}},
    {"GRID_NUM",       {Column::INT32,      0, OFFSET(WEATHER, GRID_NUM),       sizeof(WEATHER::GRID_NUM)}},
    {"DATA",           {Column::STRUCT,     0, OFFSET(WEATHER, DATA),           sizeof(WEATHER::DATA)}},
    {"OBSERVED_TIME",  {Column::TIME,       0, OFFSET(WEATHER, OBSERVED_TIME),  sizeof(WEATHER::OBSERVED_TIME)}},
}});

WeatherIndexer* gWEATHERIndexer = new WeatherIndexer;
const ::Entity::IndexerCache gWEATHERIndexerCache(gWEATHERIndexer);

/*--------1---------2---------3---------4---------5---------6---------7------*/
}   // end namespace StubEntity
