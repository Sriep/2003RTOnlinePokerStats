// PHoldemHandData.h: interface for the PHoldemHandData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHOLDEMHANDDATA_H__B1007FEE_319A_4E39_BADF_9D4926CED3ED__INCLUDED_)
#define AFX_PHOLDEMHANDDATA_H__B1007FEE_319A_4E39_BADF_9D4926CED3ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PHoldemHand.h"
#include "PCard.h"
#include "PPokerHand.h"

class PHoldemHandData : public PHoldemHand  
{
public:
	PHoldemHandData();
	virtual ~PHoldemHandData();
	PHoldemHandData(PCard cardHigh, PCard cardLow);

	float EV() const;
	void won();
	void loss();
	void draw();
	void addHandType(HAND_TYPE eHandType);
	void addHandTypeWin(HAND_TYPE eHandType);
	void addHandTypeLoss(HAND_TYPE eHandType);
	void addHandTypeDraw(HAND_TYPE eHandTypen);

	float getPercetageDraw(HAND_TYPE eHandType) const;
	float getPercetageWin(HAND_TYPE eHandType) const;
	float getPercetageLoss(HAND_TYPE eHandType) const;
    float PHoldemHandData::getPercetage(HAND_TYPE eHandType) const;

private:
	unsigned long m_lWins;
	unsigned long m_lTests;
	unsigned long m_lHandType[9];
	unsigned long m_lHandTypeWin[9];
	unsigned long m_lHandTypeLoss[9];
	unsigned long m_lHandTypeDraw[9];
};

inline void PHoldemHandData::addHandType(HAND_TYPE eHandType)
{
	m_lHandType[eHandType] += 2;
}

inline void PHoldemHandData::addHandTypeWin(HAND_TYPE eHandType) 
{
	m_lHandTypeWin[eHandType] += 2;
}

inline void PHoldemHandData::addHandTypeLoss(HAND_TYPE eHandType) 
{
	m_lHandTypeLoss[eHandType] += 2;
}

inline void PHoldemHandData::addHandTypeDraw(HAND_TYPE eHandType) 
{
	m_lHandTypeDraw[eHandType] += 2;
}

inline float PHoldemHandData::EV() const
{
	if (0 == m_lTests)
	{
		return -1;
	}
	return (float)m_lWins/m_lTests;
}

inline float PHoldemHandData::getPercetage(HAND_TYPE eHandType) const
{
	return (float)(m_lHandType[eHandType] * 100)/m_lTests;
}

inline float PHoldemHandData::getPercetageWin(HAND_TYPE eHandType) const
{
	if (0 == m_lTests)
	{
		return -1;
	}
	return (float)(m_lHandTypeWin[eHandType] * 100)/m_lTests;
}

inline float PHoldemHandData::getPercetageLoss(HAND_TYPE eHandType) const
{
	if (0 == m_lTests)
	{
		return -1;
	}
	return (float)(m_lHandTypeLoss[eHandType] * 100)/m_lTests;
}

inline float PHoldemHandData::getPercetageDraw(HAND_TYPE eHandType) const
{
	if (0 == m_lTests)
	{
		return -1;
	}
	return (float)(m_lHandTypeDraw[eHandType] * 100)/m_lTests;
}

inline void PHoldemHandData::won()
{
   m_lWins+=2;
   m_lTests+=2;
}

inline void PHoldemHandData::loss()
{
   m_lTests+=2;
}

inline void PHoldemHandData::draw()
{ 
   m_lWins++;
   m_lTests+=2;
}


#endif // !defined(AFX_PHOLDEMHANDDATA_H__B1007FEE_319A_4E39_BADF_9D4926CED3ED__INCLUDED_)
