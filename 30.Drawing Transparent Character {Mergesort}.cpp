#include <iostream>

void MergeSortRenderSubList(std::vector<CCharacter*>& apRenderList, size_t iStart, size_t iEnd)
{
	// iStart is the index of the first index that we are to sort. iEnd is the index+1 of the last index we are to sort.
	size_t iLength = iEnd - iStart;

	if (iLength <= 1)
	{
		// We are in a base case of one item. We're sorted! Return.
		return;
	}
	else if (iLength == 2)
	{
		// We are in a base case of two items. If the first one is bigger than the second, swap them.
		float flLeftDistanceSqr = (apRenderList[iStart]->m_mTransform.GetTranslation() - Game()->GetRenderer()->GetCameraPosition()).LengthSqr();
		float flRightDistanceSqr = (apRenderList[iStart+1]->m_mTransform.GetTranslation() - Game()->GetRenderer()->GetCameraPosition()).LengthSqr();

		// We can compare square distances just like regular distances, and they're faster to calculate. http://www.youtube.com/watch?v=DxmGxkhhluU
		if (flLeftDistanceSqr > flRightDistanceSqr)
			std::swap(apRenderList[iStart], apRenderList[iStart+1]);

		// Now we're sorted!
		return;
	}

	// We aren't in a base case yet. Split the list in two.
	size_t iMiddle = (iStart + iEnd)/2;

	// Sort the two sub-lists by calling this function recursively.
	MergeSortRenderSubList(apRenderList, iStart, iMiddle);
	MergeSortRenderSubList(apRenderList, iMiddle, iEnd);

	// Merge the two sub-lists together by plucking off the lowest element.
	// First make a copy of the list.
	std::vector<CCharacter*> apRenderListCopy = apRenderList;

	size_t iLeft = iStart;
	size_t iRight = iMiddle;
	size_t iOutput = iStart;
	while (true)
	{
		float flLeftDistanceSqr = (apRenderListCopy[iLeft]->m_mTransform.GetTranslation() - Game()->GetRenderer()->GetCameraPosition()).LengthSqr();
		float flRightDistanceSqr = 0;
		if (iRight != iEnd)
			flRightDistanceSqr = (apRenderListCopy[iRight]->m_mTransform.GetTranslation() - Game()->GetRenderer()->GetCameraPosition()).LengthSqr();

		// We can compare square distances just like regular distances, and they're faster to calculate. http://www.youtube.com/watch?v=DxmGxkhhluU
		bool bUseLeft = flLeftDistanceSqr < flRightDistanceSqr;
		if (iRight == iEnd)
			bUseLeft = true;
		else if (iLeft == iMiddle)
			bUseLeft = false;

		if (bUseLeft)
			apRenderList[iOutput++] = apRenderListCopy[iLeft++];
		else
			apRenderList[iOutput++] = apRenderListCopy[iRight++];

		// If we're reached the end of both sub-lists, break from the loop.
		if (iLeft == iMiddle && iRight == iEnd)
			break;
	}

	// Our sub-list is sorted! Return.
}
