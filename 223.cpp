/*
 *	223. Rectangle Area
 *	Find the total area covered by two rectilinear rectangles in a 2D plane.
 *	Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
 *	Assume that the total area is never beyond the maximum possible value of int.
 */

/*
 *	有点像图像上计算两个矩形的交并比的时候的运算,只不过是算两个矩形站的总面积
 *	第一个矩形为左下角坐标(A,B),右上角坐标(C,D)
 	第二个矩形为左下角坐标(E,F),右上角坐标(G,H)
 */
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int area1 = (C - A)*(D - B), area2 = (G - E)*(H - F);
	int bl_x, bl_y, tr_x, tr_y;	//相交部分的面积
	bl_x = max(A, E);
	bl_y = max(B, F);
	tr_x = min(C, G);
	tr_y = min(D, H);
	if (tr_x < bl_x || tr_y < bl_y) return area1 + area2;	//若没有相交部分
	else return area1 + area2 - (tr_x - bl_x)*(tr_y - bl_y);
}