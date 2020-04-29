#include <3ds.h>
#include <stdio.h>

int main()
{

	gfxInitDefault();
	consoleInit(GFX_TOP,NULL);
	
	printf("\x1b[15;19HHEllo World!");
	printf("\x1b[29;15HPress Start to exit.");	
	
	while(aptMainLoop())
	{
		hidScanInput();
		u32 kDown = hidKetsDown();
		
		if(kDown & KEY_START) break;
		
		gfxFlushBuffers();
		gfxSwaphBuffers();
	}
	
	gspWaotForVBlank();
	gfxExit();
	return 0;
}
