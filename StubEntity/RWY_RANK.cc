/*--------1---------2---------3---------4---------5---------6---------7---*//**
* @file
*     モジュール名：業務データテーブル情報構造体
* <pre>
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
**//*-----1---------2---------3---------4---------5---------6---------7------*/

#include <StubEntity/RWY_RANK.h>

namespace StubEntity {

using ::Entity::Column;

constexpr char RWY_RANK::ENTITY_NAME[];
constexpr char RwyRankIndexer::INDEXER_NAME[];

RwyRankIndexer::RwyRankIndexer() {
}

RwyRankIndexer::~RwyRankIndexer() {
}

int RwyRankIndexer::compare(const ::Entity::AbstEntity& obj1,
        const ::Entity::AbstEntity& obj2) const {
    const RWY_RANK& def1 = static_cast<const RWY_RANK&>(obj1);
    const RWY_RANK& def2 = static_cast<const RWY_RANK&>(obj2);
    return def1.RWY_RANK - def2.RWY_RANK;
}

const ::std::string RwyRankIndexer::getIndexerName() const {
    return INDEXER_NAME;
}

/*--------1---------2---------3---------4---------5---------6---------7------*/
RwyRankMatcher::RwyRankMatcher(int rank) : rank(rank) {
}

int RwyRankMatcher::match(const ::Entity::AbstEntity& obj) const {
    return static_cast<const RWY_RANK&>(obj).RWY_RANK - rank;
}

/*--------1---------2---------3---------4---------5---------6---------7------*/
RwyRankIndexMatcher::RwyRankIndexMatcher(const ::std::string& name, int rank) :
    ::Entity::AbstIndexMatcher(name), rank(rank) {
}

void RwyRankIndexMatcher::setRank(int rank) {
    this->rank = rank;
}

int RwyRankIndexMatcher::match(const ::Entity::AbstEntity& obj) const {
    return static_cast<const RWY_RANK&>(obj).RWY_RANK - rank;
}

/*--------1---------2---------3---------4---------5---------6---------7------*/
RwyRankSorter::RwyRankSorter() {
}

int RwyRankSorter::compare(const ::Entity::AbstEntity& obj1,
        const ::Entity::AbstEntity& obj2) const {
    const RWY_RANK& data1 = static_cast<const RWY_RANK&>(obj1);
    const RWY_RANK& data2 = static_cast<const RWY_RANK&>(obj2);
    return data1.RWY_RANK - data2.RWY_RANK;
}

/*--------1---------2---------3---------4---------5---------6---------7------*/
const ::Entity::EntityCache gRWY_RANK(
        RWY_RANK::ENTITY_NAME, { sizeof(RWY_RANK), {
    {"RWY_RANK",           {Column::INT32,      1, OFFSET(RWY_RANK, RWY_RANK),              sizeof(RWY_RANK::RWY_RANK)}},
    {"RWY_NAME",           {Column::CHAR_ARRAY, 1, OFFSET(RWY_RANK, RWY_NAME),              sizeof(RWY_RANK::RWY_NAME)}},
    {"AIRPORT",            {Column::CHAR_ARRAY, 1, OFFSET(RWY_RANK, AIRPORT),               sizeof(RWY_RANK::AIRPORT)}},
    {"FOID",               {Column::CHAR_ARRAY, 0, OFFSET(RWY_RANK, FOID),                  sizeof(RWY_RANK::FOID)}},
    {"CALC_TIME",          {Column::TIME,       0, OFFSET(RWY_RANK, CALC_TIME),             sizeof(RWY_RANK::CALC_TIME)}},
    {"DEP_ARR_ID",         {Column::CHAR_ARRAY, 0, OFFSET(RWY_RANK, DEP_ARR_ID),            sizeof(RWY_RANK::DEP_ARR_ID)}},
    {"TIME",               {Column::TIME,       0, OFFSET(RWY_RANK, TIME),                  sizeof(RWY_RANK::TIME)}},
    {"CALC_TRJ_NO",        {Column::INT32,      0, OFFSET(RWY_RANK, CALC_TRJ_NO),           sizeof(RWY_RANK::CALC_TRJ_NO)}},
    {"CALC_TRJ_UP_VERSION",{Column::INT32,      0, OFFSET(RWY_RANK, CALC_TRJ_UP_VERSION),   sizeof(RWY_RANK::CALC_TRJ_UP_VERSION)}},
}});

const ::Entity::IndexerCache gRWY_RANKIndexer(new RwyRankIndexer());

/*--------1---------2---------3---------4---------5---------6---------7------*/
}   // end namespace StubEntity
