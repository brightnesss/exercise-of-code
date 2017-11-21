
/*
 *  You are given an n x n 2D matrix representing an image.
 *  Rotate the image by 90 degrees (clockwise).

 *  Note:
 *  You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 *  Example 1:
 *  Given input matrix = 
    [
     [1,2,3],
     [4,5,6],
     [7,8,9]
    ],

 *  rotate the input matrix in-place such that it becomes:
    [
     [7,4,1],
     [8,5,2],
     [9,6,3]
    ]


 *  Example 2:
 *  Given input matrix =
    [
     [ 5, 1, 9,11],
     [ 2, 4, 8,10],
     [13, 3, 6, 7],
     [15,14,12,16]
    ], 

 *  rotate the input matrix in-place such that it becomes:
    [
     [15,13, 2, 5],
     [14, 3, 4, 1],
     [12, 6, 8, 9],
     [16, 7,10,11]
    ]

 */


//最简单的思路,循环移位,从上面的行开始
//每次需要把上面的行记录下来
void rotate(vector<vector<int>>& matrix)
{
  int n = matrix.size(), step(n - 1), posi(0), posj(0);
  int end(n / 2);
  vector<int> bin;
  for (int num = 0;num < end;++num)
  {
    bin.clear();
    for (int j = num;j < n - num;++j) bin.push_back(matrix[num][j]);
    int i(num), j(num);

    posi = num, posj = num;
    while (i < n - num)
    {
      posj = j + (step - (i - posi));
      matrix[posi][posj] = matrix[i][j];
      ++i;
    }
    i -= 1;

    posi = i, posj = j;
    while (j < n - num)
    {
      posi = i - (step - (j - posj));
      matrix[posi][posj] = matrix[i][j];
      ++j;
    }
    j -= 1;

    posi = i, posj = j;
    while (i >= num)
    {
      posj = j - (step - (posi - i));
      matrix[posi][posj] = matrix[i][j];
      --i;
    }
    i += 1;

    posi = i, posj = j;
    while (true)
    {
      for (int tmp = 0;tmp < bin.size();++tmp)
      {
        matrix[posi][posj] = bin[tmp];
        ++posi;
      }
      break;
    }
    step -= 2;
  }
}


//可以用swap...
//我真的好蠢