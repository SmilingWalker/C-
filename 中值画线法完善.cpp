void Draw(int x0,int x1,int y0,int y1,color)
{
	int rx,ry,x,y,dx,dy,change,d;
	int n = pts.GetSize();

    //得到差值和系数
		dy =x1-x0;
		dx = y0-y1;
    //判断步长
		if(dy>=0)rx=1;
		else rx = -1;
		if (dx>=0)ry = -1;
		else ry = 1;
		//dx = abs(dx);
		//dy = abs(dy);
		x = pts[i].x;
		y = pts[i].y;
    //判断斜率
		if(abs(dx)<abs(dy))change = 1;
		else
		{
			change = dx;
			dx = dy;
			dy = change;
			change = -1;
		}
		int k = rx*ry;//判断斜率正负
		
    //根据斜率判断初值
    if(k == -1)
		d = 2*dx+dy;
		else d = dx*2 - dy;
    //循环打点
		for(int j = 0;j<abs(dy);j++)
		{
			pDC->SetPixel(x,y,RGB(100,150,200));
			if(change==1)
			{
				x = x+rx;
				if(d*rx<0)
				{
					y = y+ry;
					d = d+2*(dx+dy*k);
				}
				else d = d+2*dx;
			}
			else
			{
				y = y+ry;
				if(d*rx>0)
				{
					x = x +rx;
					d = d+2*(dx+dy*k);
				}
				else d = d+2*dx;

			}
		}


}
