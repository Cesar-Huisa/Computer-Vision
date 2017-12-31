
#include <CImg.h>
#include <iostream>

using namespace std;
using namespace cimg_library;

int main(int argc,char *argv[])
{
	// definimos la escena 3d con varios objetos
	std::fprintf(stderr,"probando probando\n");

	// definimos los vertices y primitivas
	CImgList<unsigned int> cube_prims,plane_prims,scene_prims;
	CImg<float>
		cube_pts = CImg<>::box3d(cube_prims,512,512,149).shift_object3d().shift_object3d(-5,-10,45),
		plane_pts = CImg<>::plane3d(plane_prims,700,700,20,20).shift_object3d().shift_object3d(0,0,40);
  plane_prims.insert(plane_prims.get_reverse_object3d());
	//CImg_3x3x3(I,unsigned int);
	//	CImg<float> gradnorm(cube_pts);
	/*
	cimg_for3x3x3(cube_pts,x,y,z,0,I,unsigned int) { // Loop over the volume, using the neighborhood I
          // Compute the derivative along the z-axis.
  	cube_pts(x,y,z)=123;  // Set the gradient norm in the destination image
  }*/

		for(int y=1;y<50;y++)
			for(int x=1;x<50;x++){
				cout<<"x: "<<x<<" y : "<<y<<endl;
				plane_pts(y,x)=255;
			}
	//cout<<"los boxeles diferentes de cero son : "<<noCero<<endl;
	//cube_pts.display();
  //cube_pts.display("Gradient norm");
	// definimos los colores y texturas
	const CImgList<unsigned char>
	plane_cols = CImgList<unsigned char>(plane_prims.size(),CImg<unsigned char>::vector(200,200,200)),
	cube_cols = CImgList<unsigned char>(cube_prims.size(),CImg<unsigned char>::vector(123,123,123));
	const CImg<unsigned char> texture = CImg<unsigned char>("milla.bmp").resize(128,128);

	// definimos las opacidades
	const CImg<float>
		cube_opacs(cube_prims.size(),1,1,1,1.0f),
    plane_opacs(plane_prims.size(),1,1,1,1.0f);

  //juntamos todo a la escena 3d
  const CImg<float> scene_pts = CImg<float>().
  	append_object3d(scene_prims,cube_pts,cube_prims).
    append_object3d(scene_prims,plane_pts,plane_prims);
	const CImgList<unsigned char> scene_cols = (+cube_cols,plane_cols);
  const CImg<float> scene_opacs = (cube_opacs,plane_opacs)>'x';

	// mostramos el objeto 3d en la interfas de usuario y obtenemos la matriz final
	std::fprintf(stderr," - Display 3D Scene.\n");
  const CImg<unsigned char> visu = CImg<unsigned char>(3,512,512,1).fill(230,230,255).permute_axes("yzcx");
  CImg<float> view_matrix = CImg<>::identity_matrix(4);
  visu.display_object3d("3D Scene",scene_pts,scene_prims,scene_cols,scene_opacs,true,4,4,false,500.0f,0,0,-5000,0.5f,0.1f,true,view_matrix.data());

	// guardamos el objeto 3d como archivo OFF
	std::fprintf(stderr," - Save .OFF 3D object file.\n");
	scene_pts.save_off(scene_prims,scene_cols,"output.off");
	// salimos
	std::fprintf(stderr," - Exit.\n");

	return 0;
}
