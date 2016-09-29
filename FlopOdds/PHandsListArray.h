// PHandsListArray.h: interface for the PHandsListArray class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHANDSLISTARRAY_H__16034BCC_9DB6_4A13_8156_9D782F454EEA__INCLUDED_)
#define AFX_PHANDSLISTARRAY_H__16034BCC_9DB6_4A13_8156_9D782F454EEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "HandsMap.h"
#include "HandsMap.h"
#include "PGameBoard.h"

class PHandsListArray  
{
public:
	PHandsListArray();
	virtual ~PHandsListArray();

	void Set(PHandsList* array);
	PHandsList* GetPtr(int index) ;
	PHandsList& Get(int index);
	void SetRandomSample();
	std::list <PCard>& GetCardsInSample();
	PPokerHand FindBestHand(PGameBoard board);

private:
	PHandsList m_HandLists[9];
	PHoldemHand m_RandomSample[9];
	int m_iNumberOfLists;
	std::list <PCard> m_SampleCardList;

};

inline PHandsList* PHandsListArray::GetPtr(int index) 
{
	ASSERT(index >= 0 && index < 9);
	return 	&m_HandLists[index];
}

inline PHandsList& PHandsListArray::Get(int index) 
{
	ASSERT(index >= 0 && index < 9);
	return 	m_HandLists[index];
}

inline	std::list <PCard>& PHandsListArray::GetCardsInSample()
{
	return m_SampleCardList;
}

inline void PHandsListArray::SetRandomSample()
{
    m_SampleCardList.clear();
	m_iNumberOfLists = 0;
	for (int i=0 ; i < 9 ; i++)
	{
		if (m_HandLists[i].size() > 0)
		{
			m_RandomSample[m_iNumberOfLists] = m_HandLists[i].GetRandomHand(m_SampleCardList);
			m_SampleCardList.push_back(m_RandomSample[m_iNumberOfLists].getHighCard());
			m_SampleCardList.push_back(m_RandomSample[m_iNumberOfLists].getLowCard());
			m_iNumberOfLists++;
		}
	}
}

inline PPokerHand PHandsListArray::FindBestHand(PGameBoard board)
{
	ASSERT(m_iNumberOfLists > 0);
	PPokerHand bestSoFar = board.GetBestHand(m_RandomSample[0]);
	for ( int index = 1 ; index < m_iNumberOfLists ; index++ )
	{
		PPokerHand next = board.GetBestHand(m_RandomSample[index]);
		if (next > bestSoFar)
		{
			bestSoFar = next;
		}
	}
	return bestSoFar;
}



#endif // !defined(AFX_PHANDSLISTARRAY_H__16034BCC_9DB6_4A13_8156_9D782F454EEA__INCLUDED_)

