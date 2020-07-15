#include <3ds.h>
#include <stdio.h>

int main()
{

	srvInit();
	aptInit();
	hidInit();;
	gfxSet3D(false);
	gfxInitDefault();
	
	consoleInit(GFX_TOP,NULL);
	
	printf("\x1b[15;19HHEllo World!");
	printf("\x1b[29;15HPress Start to exit.");	
	
	while(aptMainLoop())
	{
		hidScanInput();
		gspWaitForVBlank();
	
		touchPosition touch;
		hidTouchRead(&touch);
		printf("\x1b[0;0hx coordinate: %i ", touch.px);
		printf("\x1b[1;0hy coordinate: %i ", touch.py);
		
		u32 kDown = hidKeysDown();
		u32 kHeld = hidKeysHeld();
		if(kHeld & KEY_TOUCH)
		{
			printf("\x1b[2;0HIis Active:True");	
		}
		else
		{
			printf("\x1b[2;0HIs Active:False);
		}
		if(kDown & KEY_START) break;
		
		gfxFlushBuffers();
		gfxSwaphBuffers();
	}
	
	hidExit();
  	aptExit();
  	srvExit();
	gfxExit();
	return 0;
}
