class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int total_size = (n + m); 

        int i = 0;
        int j = 0;

        int count = 0;
        int index2 = total_size / 2;
        int index1 = index2 - 1;

        int index1_el = -1;
        int index2_el = -1;
        
        while(i<n && j<m)
        {
            if(nums1[i] < nums2[j])
            {
                if(count == index1) index1_el = nums1[i];
                if(count == index2) index2_el = nums1[i];
                count ++;
                i++;
            }
            else
            {
                if(count == index1) index1_el = nums2[j];
                if(count == index2) index2_el = nums2[j];
                count ++;
                j++;
            }
        }

        while(i<n)
        {
            if(count == index1) index1_el = nums1[i];
            if(count == index2) index2_el = nums1[i];
            count ++;
            i++;
        }

        while(j<m)
        {
            if(count == index1) index1_el = nums2[j];
            if(count == index2) index2_el = nums2[j];
            count ++;
            j++;
        }

        if(total_size % 2 == 1)
        {
            return index2_el;
        }

        return (double) ((double) (index1_el + index2_el)) / 2.0;
    }
};