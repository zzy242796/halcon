///////////////////////////////////////////////////////////////////////////////
// File generated by HDevelop for HALCON/C++ Version 24.11.1.0
// Non-ASCII strings in this file are encoded in local-8-bit encoding (cp936).
// Ensure that the interface encoding is set to locale encoding by calling
// SetHcppInterfaceStringEncodingIsUtf8(false) at the beginning of the program.
// 
// Please note that non-ASCII characters in string constants are exported
// as octal codes in order to guarantee that the strings are correctly
// created on all systems, independent on any compiler settings.
// 
// Source files with different encoding should not be mixed in one project.
///////////////////////////////////////////////////////////////////////////////
#include "HalconCpp.h"
#include "HDevThread.h"



using namespace HalconCpp;

// Procedure declarations 
// Chapter: Develop
// Short Description: Open a new graphics window that preserves the aspect ratio of the given image. 
void dev_open_window_fit_image (HObject ho_Image, HTuple hv_Row, HTuple hv_Column, 
    HTuple hv_WidthLimit, HTuple hv_HeightLimit, HTuple *hv_WindowHandle);

// Procedures 
// Chapter: Develop
// Short Description: Open a new graphics window that preserves the aspect ratio of the given image. 
void dev_open_window_fit_image (HObject ho_Image, HTuple hv_Row, HTuple hv_Column, 
    HTuple hv_WidthLimit, HTuple hv_HeightLimit, HTuple *hv_WindowHandle)
{

  // Local iconic variables

  // Local control variables
  HTuple  hv_MinWidth, hv_MaxWidth, hv_MinHeight;
  HTuple  hv_MaxHeight, hv_ResizeFactor, hv_ImageWidth, hv_ImageHeight;
  HTuple  hv_TempWidth, hv_TempHeight, hv_WindowWidth, hv_WindowHeight;

  //This procedure opens a new graphics window and adjusts the size
  //such that it fits into the limits specified by WidthLimit
  //and HeightLimit, but also maintains the correct image aspect ratio.
  //
  //If it is impossible to match the minimum and maximum extent requirements
  //at the same time (f.e. if the image is very long but narrow),
  //the maximum value gets a higher priority,
  //
  //Parse input tuple WidthLimit
  if (0 != (HTuple(int((hv_WidthLimit.TupleLength())==0)).TupleOr(int(hv_WidthLimit<0))))
  {
    hv_MinWidth = 500;
    hv_MaxWidth = 800;
  }
  else if (0 != (int((hv_WidthLimit.TupleLength())==1)))
  {
    hv_MinWidth = 0;
    hv_MaxWidth = hv_WidthLimit;
  }
  else
  {
    hv_MinWidth = ((const HTuple&)hv_WidthLimit)[0];
    hv_MaxWidth = ((const HTuple&)hv_WidthLimit)[1];
  }
  //Parse input tuple HeightLimit
  if (0 != (HTuple(int((hv_HeightLimit.TupleLength())==0)).TupleOr(int(hv_HeightLimit<0))))
  {
    hv_MinHeight = 400;
    hv_MaxHeight = 600;
  }
  else if (0 != (int((hv_HeightLimit.TupleLength())==1)))
  {
    hv_MinHeight = 0;
    hv_MaxHeight = hv_HeightLimit;
  }
  else
  {
    hv_MinHeight = ((const HTuple&)hv_HeightLimit)[0];
    hv_MaxHeight = ((const HTuple&)hv_HeightLimit)[1];
  }
  //
  //Test, if window size has to be changed.
  hv_ResizeFactor = 1;
  GetImageSize(ho_Image, &hv_ImageWidth, &hv_ImageHeight);
  //First, expand window to the minimum extents (if necessary).
  if (0 != (HTuple(int(hv_MinWidth>hv_ImageWidth)).TupleOr(int(hv_MinHeight>hv_ImageHeight))))
  {
    hv_ResizeFactor = (((hv_MinWidth.TupleReal())/hv_ImageWidth).TupleConcat((hv_MinHeight.TupleReal())/hv_ImageHeight)).TupleMax();
  }
  hv_TempWidth = hv_ImageWidth*hv_ResizeFactor;
  hv_TempHeight = hv_ImageHeight*hv_ResizeFactor;
  //Then, shrink window to maximum extents (if necessary).
  if (0 != (HTuple(int(hv_MaxWidth<hv_TempWidth)).TupleOr(int(hv_MaxHeight<hv_TempHeight))))
  {
    hv_ResizeFactor = hv_ResizeFactor*((((hv_MaxWidth.TupleReal())/hv_TempWidth).TupleConcat((hv_MaxHeight.TupleReal())/hv_TempHeight)).TupleMin());
  }
  hv_WindowWidth = hv_ImageWidth*hv_ResizeFactor;
  hv_WindowHeight = hv_ImageHeight*hv_ResizeFactor;
  //Resize window
  SetWindowAttr("background_color","black");
  OpenWindow(hv_Row,hv_Column,hv_WindowWidth,hv_WindowHeight,0,"visible","",&(*hv_WindowHandle));
  HDevWindowStack::Push((*hv_WindowHandle));
  if (HDevWindowStack::IsOpen())
    SetPart(HDevWindowStack::GetActive(),0, 0, hv_ImageHeight-1, hv_ImageWidth-1);
  return;
}

#ifndef NO_EXPORT_MAIN
// Main procedure 
void action()
{

  // Local iconic variables
  HObject  ho_Imageshape, ho_GrayImageshape, ho_Regionshape;
  HObject  ho_ConnectedRegionsshape, ho_SelectedRegionsshape;
  HObject  ho_RegionFillUpshape, ho_RegionDilationshape, ho_ImageReducedshape;
  HObject  ho_ModelContoursshape, ho_ContoursAffineTransshape;

  // Local control variables
  HTuple  hv_Widthshape, hv_Heightshape, hv_WindowHandle3;
  HTuple  hv_Number, hv_ModelIDshape, hv_Areashape, hv_Rowshape;
  HTuple  hv_Columnshape, hv_HomMat2Dshape, hv_WindowHandle2;
  HTuple  hv_Rowshape1, hv_Columnshape1, hv_Angleshape, hv_Scalesahpe;
  HTuple  hv_Scoreshape, hv_i, hv_HomMat2DIdentityshape, hv_HomMat2DTranslateshape;
  HTuple  hv_HomMat2DRotateshape, hv_HomMat2DScaleshape;

  ReadImage(&ho_Imageshape, "tubiao1.jpg");
  GetImageSize(ho_Imageshape, &hv_Widthshape, &hv_Heightshape);
  dev_open_window_fit_image(ho_Imageshape, 0, 0, -1, -1, &hv_WindowHandle3);
  if (HDevWindowStack::IsOpen())
    SetColor(HDevWindowStack::GetActive(),"red");
  if (HDevWindowStack::IsOpen())
    SetLineWidth(HDevWindowStack::GetActive(),3);
  if (HDevWindowStack::IsOpen())
    DispObj(ho_Imageshape, HDevWindowStack::GetActive());

  Rgb1ToGray(ho_Imageshape, &ho_GrayImageshape);
  //阈值分割
  Threshold(ho_GrayImageshape, &ho_Regionshape, 200, 255);
  //连接区域
  Connection(ho_Regionshape, &ho_ConnectedRegionsshape);
  //数目
  CountObj(ho_ConnectedRegionsshape, &hv_Number);
  //挑选
  SelectShape(ho_ConnectedRegionsshape, &ho_SelectedRegionsshape, "area", "and", 
      12000, 32000);
  //填充
  FillUp(ho_SelectedRegionsshape, &ho_RegionFillUpshape);
  //膨胀
  DilationCircle(ho_RegionFillUpshape, &ho_RegionDilationshape, 5.5);
  //抠图
  ReduceDomain(ho_GrayImageshape, ho_RegionDilationshape, &ho_ImageReducedshape);


  //创建模版   模板 金字塔 图案的最小旋转 旋转角度的大小 步长 图案最小比例 图案的最大比例 缩放步长（分辨率）
  CreateScaledShapeModel(ho_ImageReducedshape, 5, HTuple(-180).TupleRad(), HTuple(180).TupleRad(), 
      "auto", 0.2, 1.1, "auto", "none", "ignore_global_polarity", 40, 10, &hv_ModelIDshape);
  //获取模版轮廓
  GetShapeModelContours(&ho_ModelContoursshape, hv_ModelIDshape, 1);
  //显示模版轮廓到模版位置
  AreaCenter(ho_RegionFillUpshape, &hv_Areashape, &hv_Rowshape, &hv_Columnshape);
  //仿射变换
  VectorAngleToRigid(0, 0, 0, hv_Rowshape, hv_Rowshape, 0, &hv_HomMat2Dshape);
  //应用任意仿射二维变换到XLD轮廓。
  AffineTransContourXld(ho_ModelContoursshape, &ho_ContoursAffineTransshape, hv_HomMat2Dshape);
  if (HDevWindowStack::IsOpen())
    DispObj(ho_Imageshape, HDevWindowStack::GetActive());
  if (HDevWindowStack::IsOpen())
    DispObj(ho_ContoursAffineTransshape, HDevWindowStack::GetActive());

  // stop(...); only in hdevelop
  if (HDevWindowStack::IsOpen())
    CloseWindow(HDevWindowStack::Pop());
  ReadImage(&ho_Imageshape, "tubiao3.png");
  dev_open_window_fit_image(ho_Imageshape, 0, 0, -1, -1, &hv_WindowHandle2);
  Rgb1ToGray(ho_Imageshape, &ho_GrayImageshape);
  if (HDevWindowStack::IsOpen())
    DispObj(ho_Imageshape, HDevWindowStack::GetActive());
  //匹配模版
  FindScaledShapeModel(ho_GrayImageshape, hv_ModelIDshape, HTuple(-180).TupleRad(), 
      HTuple(180).TupleRad(), 0.2, 1.1, 0.3, 0, 0.5, "least_squares", 5, 0.5, &hv_Rowshape1, 
      &hv_Columnshape1, &hv_Angleshape, &hv_Scalesahpe, &hv_Scoreshape);
  //循环显示匹配出来的模版区域轮廓
  {
  HTuple end_val43 = (hv_Scoreshape.TupleLength())-1;
  HTuple step_val43 = 1;
  for (hv_i=0; hv_i.Continue(end_val43, step_val43); hv_i += step_val43)
  {
    //生成相同二维变换的齐次变换矩阵。
    HomMat2dIdentity(&hv_HomMat2DIdentityshape);
    //向齐次二维变换矩阵添加一个平移。
    HomMat2dTranslate(hv_HomMat2DIdentityshape, HTuple(hv_Rowshape1[hv_i]), HTuple(hv_Columnshape1[hv_i]), 
        &hv_HomMat2DTranslateshape);
    //添加一个旋转到齐次二维变换矩阵。
    HomMat2dRotate(hv_HomMat2DTranslateshape, HTuple(hv_Angleshape[hv_i]), HTuple(hv_Rowshape1[hv_i]), 
        HTuple(hv_Columnshape1[hv_i]), &hv_HomMat2DRotateshape);
    //向齐次二维变换矩阵添加缩放。
    HomMat2dScale(hv_HomMat2DRotateshape, HTuple(hv_Scalesahpe[hv_i]), HTuple(hv_Scalesahpe[hv_i]), 
        HTuple(hv_Rowshape1[hv_i]), HTuple(hv_Columnshape1[hv_i]), &hv_HomMat2DScaleshape);
    //应用任意仿射二维变换到XLD轮廓。
    AffineTransContourXld(ho_ModelContoursshape, &ho_ContoursAffineTransshape, hv_HomMat2DScaleshape);
    if (HDevWindowStack::IsOpen())
      DispObj(ho_ContoursAffineTransshape, HDevWindowStack::GetActive());
       stop()
  }
  }

  ClearShapeModel(hv_ModelIDshape);
}


#ifndef NO_EXPORT_APP_MAIN


int main(int argc, char *argv[])
{
  int ret = 0;

  try
  {
#if defined(_WIN32)
    SetSystem("use_window_thread", "true");
#endif

    // file was stored with local-8-bit encoding
    //   -> set the interface encoding accordingly
    SetHcppInterfaceStringEncodingIsUtf8(false);

    // Default settings used in HDevelop (can be omitted)
    SetSystem("width", 512);
    SetSystem("height", 512);

    action();
  }
  catch (HException &exception)
  {
    fprintf(stderr,"  Error #%u in %s: %s\n", exception.ErrorCode(),
            exception.ProcName().TextA(),
            exception.ErrorMessage().TextA());
    ret = 1;
  }

#if defined(_WIN32)
  // On Windows socket communication is no longer possible after returning
  // from main, so HALCON cannot return floating licenses automatically.
  try
  {
    SetSystem("return_license", "true");
  }
  catch (...)
  {
    // Ignore any errors that might occur when returning the license.
  }
#endif

  return ret;
}

#endif


#endif


