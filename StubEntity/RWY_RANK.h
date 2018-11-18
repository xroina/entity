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

#ifndef _RWY_RANK_H_
#define _RWY_RANK_H_

#include <string>
#include <PBase>

namespace StubEntity {

class RWY_RANK : public ::Entity::AbstEntity {

public:
    static constexpr char ENTITY_NAME[] = "RWY_RANK";

    int  RWY_RANK;
    char RWY_NAME[ 3 + 1];
    char AIRPORT[ 4 + 1];
    char FOID[16 + 1];
    ::Time::time CALC_TIME;
    char DEP_ARR_ID[ 1 + 1];
    ::Time::time TIME;
    int  CALC_TRJ_NO;
    int  CALC_TRJ_UP_VERSION;

};

/*--------1---------2---------3---------4---------5---------6---------7------*/
class RwyRankIndexer : public ::Entity::ImplIndexer {
public:
    static constexpr char INDEXER_NAME[] = "RwyRankIndexer";
    RwyRankIndexer();
    ~RwyRankIndexer();
    int compare(const ::Entity::AbstEntity&, const ::Entity::AbstEntity&) const;

    const ::std::string getIndexerName() const;
};

/*--------1---------2---------3---------4---------5---------6---------7------*/
class RwyRankMatcher : public ::Entity::ImplMatcher {
    int rank;
public:
    RwyRankMatcher(int rank);
    int match(const ::Entity::AbstEntity& obj) const;
};

/*--------1---------2---------3---------4---------5---------6---------7------*/
class RwyRankIndexMatcher : public ::Entity::AbstIndexMatcher {
    int rank;
public:
    RwyRankIndexMatcher(const ::std::string&, int);
    void setRank(int);
    int match(const ::Entity::AbstEntity&) const;
};

/*--------1---------2---------3---------4---------5---------6---------7------*/
class RwyRankSorter : public ::Entity::ImplSorter {
public:
    RwyRankSorter();
    int compare(const ::Entity::AbstEntity&, const ::Entity::AbstEntity&) const;
};

/*--------1---------2---------3---------4---------5---------6---------7------*/
}   // end namespace StubEntity

#endif/* _RWY_RANK_H_ */

