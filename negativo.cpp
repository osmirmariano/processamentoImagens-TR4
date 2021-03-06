//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "negativo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    Form1->Color = clWhite;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
	Image1->Picture->LoadFromFile("bears.bmp"); // Carregando imagem
	Image1->Stretch = true; //redimensiona
	Image1->Refresh(); //atualiza
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	/*o negativo de uma imagem, calculando o novo valor de cada pixel como:
	<novo valor> = 255 - <antigo valor>. No caso de imagens coloridas, aplique o algoritmo
	para cada um dos canais (R,G,B)*/

	int x, y, r, g, b;
	for(x = 0; x < IntToStr(Image1->Width); x++){
		for(y = 0; y < IntToStr(Image1->Height); y++){
			cor = Image1->Canvas->Pixels[x][y];
			r = GetRValue(cor);
			g = GetGValue(cor);
			b = GetBValue(cor);//

//			r = 255-r;
//			g = 255-g;
//			b = 255-b;

			Image1->Canvas->Pixels[x][y] = 255+RGB(-r,-g,-b);
		}
	}
}
//---------------------------------------------------------------------------

