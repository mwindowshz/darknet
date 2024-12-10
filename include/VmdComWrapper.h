

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Thu Aug 17 14:47:50 2023
 */
/* Compiler settings for vmdComWarper.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __VmdComWrapper_h__
#define __VmdComWrapper_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICStab2_FWD_DEFINED__
#define __ICStab2_FWD_DEFINED__
typedef interface ICStab2 ICStab2;

#endif 	/* __ICStab2_FWD_DEFINED__ */


#ifndef __ICStab_FWD_DEFINED__
#define __ICStab_FWD_DEFINED__
typedef interface ICStab ICStab;

#endif 	/* __ICStab_FWD_DEFINED__ */


#ifndef ___ICStabEvents_FWD_DEFINED__
#define ___ICStabEvents_FWD_DEFINED__
typedef interface _ICStabEvents _ICStabEvents;

#endif 	/* ___ICStabEvents_FWD_DEFINED__ */


#ifndef __CStab_FWD_DEFINED__
#define __CStab_FWD_DEFINED__

#ifdef __cplusplus
typedef class CStab CStab;
#else
typedef struct CStab CStab;
#endif /* __cplusplus */

#endif 	/* __CStab_FWD_DEFINED__ */


#ifndef __FilterSetup_FWD_DEFINED__
#define __FilterSetup_FWD_DEFINED__

#ifdef __cplusplus
typedef class FilterSetup FilterSetup;
#else
typedef struct FilterSetup FilterSetup;
#endif /* __cplusplus */

#endif 	/* __FilterSetup_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_vmdComWarper_0000_0000 */
/* [local] */ 

typedef /* [public][public][public][public][public][public][public][public][public] */ 
enum __MIDL___MIDL_itf_vmdComWarper_0000_0000_0001
    {
        EVENT_VMD_IDL	= 0,
        EVENT_SOD_COME_IDL	= ( EVENT_VMD_IDL + 1 ) ,
        EVENT_SOD_GONE_IDL	= ( EVENT_SOD_COME_IDL + 1 ) ,
        EVENT_PARKING_IN_IDL	= ( EVENT_SOD_GONE_IDL + 1 ) ,
        EVENT_PARKING_OUT_IDL	= ( EVENT_PARKING_IN_IDL + 1 ) ,
        EVENT_GROUP_IDL	= ( EVENT_PARKING_OUT_IDL + 1 ) ,
        EVENT_CAMERA_HIDDEN_IDL	= ( EVENT_GROUP_IDL + 1 ) ,
        EVENT_ILLIGAL_PARKING_IDL	= ( EVENT_CAMERA_HIDDEN_IDL + 1 ) ,
        EVENT_SOD_BLOCKED_IDL	= ( EVENT_ILLIGAL_PARKING_IDL + 1 ) ,
        EVENT_SOD_IDL	= ( EVENT_SOD_BLOCKED_IDL + 1 ) ,
        EVENT_SOD_UNKNOWN_IDL	= ( EVENT_SOD_IDL + 1 ) 
    } 	PtEventTypeIDL;

typedef /* [public][public][public][public] */ 
enum __MIDL___MIDL_itf_vmdComWarper_0000_0000_0002
    {
        EVENT_START_IDL	= 1,
        EVENT_ENDED_IDL	= ( EVENT_START_IDL + 1 ) 
    } 	PtEventStatusIDL;


#pragma pack(1)
/* [uuid] */ struct  DECLSPEC_UUID("903080CB-947B-4AC9-96B0-4E9C4A7E54A5") MovingObjectData
    {
    int left;
    int top;
    int right;
    int bottom;
    int object_id;
    int age;
    int parent_object_id1;
    int parent_object_id2;
    double veloc_x;
    double veloc_y;
    int global_object_id;
    } ;
typedef struct MovingObjectData MovingObjectData;

/* [uuid] */ struct  DECLSPEC_UUID("EFE1DA18-5554-4D7E-80E9-A1A4A26533D6") MovingObjectEventIDL
    {
    PtEventTypeIDL _eventType;
    PtEventStatusIDL _eventStatus;
    int _presetId;
    int _settingNum;
    boolean _isInsideDirFilter;
    int _eventCounter;
    int _detectionGlobalID;
    int _framesSinceReported;
    } ;
typedef struct MovingObjectEventIDL MovingObjectEventIDL;


#pragma pack()
/* [uuid] */ struct  DECLSPEC_UUID("681F12E3-7CC6-42D3-9020-EC78C318511C") MovingObjectDataStructForIDL
    {
    int left;
    int top;
    int right;
    int bottom;
    int age;
    double veloc_x;
    double veloc_y;
    int obj_id;
    int combined_obj_id_1;
    int combined_obj_id_2;
    int global_object_id;
    int is_tracking_object;
    PtEventTypeIDL event_type;
    int objectPathHistoryArraySize;
    POINT objectPathHistoryArray[ 20 ];
    int zone;
    int preset_id;
    } ;
typedef struct MovingObjectDataStructForIDL MovingObjectDataStructForIDL;


enum NextFrameReturnValues
    {
        PT_FAILED_REGISTRATION	= 0,
        PT_REGISTRATION_OK	= 1,
        PT_INIT_FAILED	= -1,
        PT_BIGWIN_FREEZE	= -2,
        PT_FRAME_EXCEPTION	= -3,
        PT_HASP_PROBLEM	= -4
    } ;


extern RPC_IF_HANDLE __MIDL_itf_vmdComWarper_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vmdComWarper_0000_0000_v0_0_s_ifspec;

#ifndef __ICStab2_INTERFACE_DEFINED__
#define __ICStab2_INTERFACE_DEFINED__

/* interface ICStab2 */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_ICStab2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7A8CA643-D19C-4F3B-99E8-9DA7EF4D3A83")
    ICStab2 : public IUnknown
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NextFrame( 
            unsigned char **image,
            /* [retval][out] */ LONG *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFPS( 
            /* [retval][out] */ FLOAT *fps) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawMovingObjects( 
            /* [in] */ VARIANT hdc,
            /* [in] */ int sx,
            /* [in] */ int sy) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NextFrameAsync( 
            /* [in] */ BYTE *ppImage,
            /* [in] */ LONGLONG timeStamp,
            /* [retval][out] */ LONG *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NextFrameAsyncDotNet( 
            /* [in] */ BYTE **ppImage,
            /* [in] */ LONGLONG timeStamp,
            /* [retval][out] */ LONG *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDirectionFilter( 
            /* [in] */ int dirFilter) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetExtendedMovingObjectDataStruct( 
            /* [retval][out] */ BSTR *detectionsJsonInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendExtendedCommand( 
            /* [in] */ BSTR strCommand,
            /* [in] */ LONGLONG *data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SendExtendedCommandDotNet( 
            /* [in] */ BSTR strCommand,
            /* [in] */ LONGLONG **data) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICStab2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICStab2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICStab2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICStab2 * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NextFrame )( 
            ICStab2 * This,
            unsigned char **image,
            /* [retval][out] */ LONG *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFPS )( 
            ICStab2 * This,
            /* [retval][out] */ FLOAT *fps);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DrawMovingObjects )( 
            ICStab2 * This,
            /* [in] */ VARIANT hdc,
            /* [in] */ int sx,
            /* [in] */ int sy);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NextFrameAsync )( 
            ICStab2 * This,
            /* [in] */ BYTE *ppImage,
            /* [in] */ LONGLONG timeStamp,
            /* [retval][out] */ LONG *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NextFrameAsyncDotNet )( 
            ICStab2 * This,
            /* [in] */ BYTE **ppImage,
            /* [in] */ LONGLONG timeStamp,
            /* [retval][out] */ LONG *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDirectionFilter )( 
            ICStab2 * This,
            /* [in] */ int dirFilter);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetExtendedMovingObjectDataStruct )( 
            ICStab2 * This,
            /* [retval][out] */ BSTR *detectionsJsonInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendExtendedCommand )( 
            ICStab2 * This,
            /* [in] */ BSTR strCommand,
            /* [in] */ LONGLONG *data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SendExtendedCommandDotNet )( 
            ICStab2 * This,
            /* [in] */ BSTR strCommand,
            /* [in] */ LONGLONG **data);
        
        END_INTERFACE
    } ICStab2Vtbl;

    interface ICStab2
    {
        CONST_VTBL struct ICStab2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICStab2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICStab2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICStab2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICStab2_NextFrame(This,image,res)	\
    ( (This)->lpVtbl -> NextFrame(This,image,res) ) 

#define ICStab2_GetFPS(This,fps)	\
    ( (This)->lpVtbl -> GetFPS(This,fps) ) 

#define ICStab2_DrawMovingObjects(This,hdc,sx,sy)	\
    ( (This)->lpVtbl -> DrawMovingObjects(This,hdc,sx,sy) ) 

#define ICStab2_NextFrameAsync(This,ppImage,timeStamp,res)	\
    ( (This)->lpVtbl -> NextFrameAsync(This,ppImage,timeStamp,res) ) 

#define ICStab2_NextFrameAsyncDotNet(This,ppImage,timeStamp,res)	\
    ( (This)->lpVtbl -> NextFrameAsyncDotNet(This,ppImage,timeStamp,res) ) 

#define ICStab2_SetDirectionFilter(This,dirFilter)	\
    ( (This)->lpVtbl -> SetDirectionFilter(This,dirFilter) ) 

#define ICStab2_GetExtendedMovingObjectDataStruct(This,detectionsJsonInfo)	\
    ( (This)->lpVtbl -> GetExtendedMovingObjectDataStruct(This,detectionsJsonInfo) ) 

#define ICStab2_SendExtendedCommand(This,strCommand,data)	\
    ( (This)->lpVtbl -> SendExtendedCommand(This,strCommand,data) ) 

#define ICStab2_SendExtendedCommandDotNet(This,strCommand,data)	\
    ( (This)->lpVtbl -> SendExtendedCommandDotNet(This,strCommand,data) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICStab2_INTERFACE_DEFINED__ */


#ifndef __ICStab_INTERFACE_DEFINED__
#define __ICStab_INTERFACE_DEFINED__

/* interface ICStab */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICStab;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("04675BD0-EBB7-4640-9576-A4255819E0B3")
    ICStab : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NextFrame( 
            /* [in] */ unsigned char *image,
            /* [retval][out] */ LONG *res) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MotionAdaptivity( 
            /* [retval][out] */ int *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MotionAdaptivity( 
            /* [in] */ int newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StrongStabRange( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StrongStabRange( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageSmoothFactor( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImageSmoothFactor( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageSharpFactor( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImageSharpFactor( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableImageEnhuncement( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableImageEnhuncement( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CameraModel( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CameraModel( 
            /* [in] */ short newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ int image_size_x,
            /* [in] */ int image_size_y,
            /* [in] */ int color_channels,
            /* [in] */ int debug_mode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStabilizedImage( 
            /* [retval][out] */ unsigned char **image) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [retval][out] */ unsigned char **ver_str) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVersionStringAsInt( 
            /* [retval][out] */ LONGLONG *version) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStabilizedImageAsInt( 
            /* [retval][out] */ LONGLONG *image_pnt) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NextFrameByInt( 
            /* [in] */ int image) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetInputImageClipping( 
            /* [in] */ int left,
            /* [in] */ int top,
            /* [in] */ int right,
            /* [in] */ int bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetStabilizationRange( 
            /* [in] */ int x,
            /* [in] */ int y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLastFrameTranslation( 
            /* [out] */ int *tx,
            /* [out] */ int *ty) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenPropertiesDialog( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitMotionDetection( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMovingObjectsArray( 
            /* [out] */ CHAR **array,
            /* [retval][out] */ int *array_size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMinMotion( 
            /* [in] */ int min_motion) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetNoiseLevel( 
            /* [in] */ double err_factor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetDetection( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawMovingObjects( 
            /* [in] */ int hdc,
            /* [in] */ int sx,
            /* [in] */ int sy) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClippingForMotionDetection( 
            /* [in] */ int left,
            /* [in] */ int top,
            /* [in] */ int right,
            /* [in] */ int bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetClippingForStab( 
            /* [in] */ int left,
            /* [in] */ int top,
            /* [in] */ int right,
            /* [in] */ int bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMaskForVmd( 
            /* [in] */ CHAR *mask_obj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMaskForStab( 
            /* [in] */ CHAR *mask_obj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRegionsOfInterestFileName( 
            /* [in] */ BSTR interestFileName,
            /* [retval][out] */ SHORT *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetFramesDelayForDetection( 
            /* [in] */ LONG framesDelay) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetNumOfSlowSkips( 
            /* [in] */ ULONG numOfSlowSkips) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsPlugOk( 
            /* [retval][out] */ SHORT *isOk) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UseParamFile( 
            /* [in] */ BSTR fname) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMovingObjectsArrayAsInt( 
            /* [out] */ LONGLONG *array,
            /* [retval][out] */ int *array_size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateTrackingObject( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [retval][out] */ int *obj_id) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteTrackingObject( 
            /* [in] */ int obj_id) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitBigWin( 
            /* [in] */ LONG hwndForDrain,
            /* [in] */ LONG enableFullScreenMode,
            /* [in] */ int textureNum,
            /* [in] */ int textureNumForDisplay) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init2( 
            /* [in] */ int imageSizeX,
            /* [in] */ int imageSizeY,
            /* [in] */ int compression,
            /* [in] */ int bitPerPixel,
            /* [in] */ int topDownPic,
            /* [in] */ int YV12Frame,
            /* [in] */ int GrayResize,
            /* [in] */ int ColorResize,
            /* [in] */ int interlaceMode,
            /* [in] */ int interlaceResize,
            /* [in] */ int debug_mode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetD3dHwnd( 
            /* [retval][out] */ int *pHwnd) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowFpsAndStabInfoRect( 
            /* [in] */ LONG show) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawRegionsOfInterest( 
            /* [in] */ LONG hdc,
            /* [in] */ int flags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTransfFromLastFrame( 
            /* [retval][out] */ unsigned char **transf) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetUseStabInBigwin( 
            /* [in] */ LONG stab) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsBigWinDrawing( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTransfFromLastFrameAsInt( 
            /* [retval][out] */ int *transf) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitSOD( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawSOD( 
            /* [in] */ int hdc,
            /* [in] */ int sx,
            /* [in] */ int sy) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDetectionStatusSOD( 
            /* [out] */ BYTE *isDetected) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNextRectDetectionFromSOD( 
            /* [out] */ BYTE *isNew,
            /* [out] */ int *t,
            /* [out] */ int *l,
            /* [out] */ int *b,
            /* [out] */ int *r) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsInitSOD( 
            /* [out] */ BYTE *initFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearDetectionsSOD( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableSOD( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisableSOD( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE KillSOD( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE KillRegionsOfInterest( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableRegionsOfInterest( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DisableRegionsOfInterest( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateMaskFromBitMap( 
            /* [in] */ CHAR *bitMapInfoHeader,
            /* [in] */ CHAR *data,
            /* [in] */ UINT cellSizeX,
            /* [in] */ UINT cellSizeY,
            /* [retval][out] */ CHAR **maskClassObjPtr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteMaskObject( 
            /* [in] */ CHAR *maskObjPtr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMovingObjectsArrayIDLStruct( 
            /* [out] */ MovingObjectDataStructForIDL **detections_Array,
            /* [out] */ int *numObjects) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMovingObjectsArrayIDLStruct( 
            /* [in] */ MovingObjectDataStructForIDL *detections_Array,
            /* [in] */ int numObjects) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMovingObjectsArrayIDLStructINT( 
            /* [out] */ int *detections_Array,
            /* [out] */ int *numObjects) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowStabilizerControlWindow( 
            /* [in] */ LONG show) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetStabilizerVideoEnhancmentsValues( 
            /* [in] */ FLOAT noiseFilterVal,
            /* [in] */ FLOAT shapnessVal,
            /* [in] */ LONG brightnessVal,
            /* [in] */ FLOAT contrastVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStabilizerVideoEnhancmentsValues( 
            /* [out] */ FLOAT *noiseFilterVal,
            /* [out] */ FLOAT *shapnessVal,
            /* [out] */ LONG *brightnessVal,
            /* [out] */ FLOAT *contrastVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDrawRecivedVmdPoligons( 
            /* [in] */ LONG display) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetUseStabInBigwin( 
            /* [out] */ LONG *stab) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateMaskFromBitMap2( 
            /* [in] */ CHAR *fullfile,
            /* [in] */ ULONG cellSizeX,
            /* [in] */ ULONG cellSizeY,
            /* [retval][out] */ ULONG *maskClassObjPtr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateMaskFromBitMap2AsInt( 
            /* [in] */ LONGLONG fullfilePointer,
            /* [in] */ ULONG cellSizeX,
            /* [in] */ ULONG cellSizeY,
            /* [retval][out] */ ULONG *maskClassObjPtr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMaskForVmdAsInt( 
            /* [in] */ LONGLONG mask_obj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMaskForStabAsInt( 
            /* [in] */ LONGLONG mask_obj) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetBigwinShiftZoomAndRot( 
            /* [in] */ FLOAT zoom,
            /* [in] */ FLOAT zoom_center_x,
            /* [in] */ FLOAT zoom_center_y,
            /* [in] */ FLOAT rot,
            /* [in] */ FLOAT shift_x,
            /* [in] */ FLOAT shift_y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOverlayBitmaps( 
            /* [in] */ unsigned char *firstOverlayBitmap,
            /* [in] */ unsigned char *secondOverlayBitmap,
            /* [in] */ int sizeX,
            int sizeY,
            int bitPerPixel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawOverlayBitmaps( 
            /* [in] */ int drawOverly1,
            /* [in] */ int drawOverlay2,
            /* [in] */ int drawOrder) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FreezeBigWinImage( 
            /* [in] */ LONG freeze) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveBigWinFrameToMemory( 
            /* [in] */ LONG save) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSavedBigWinFrame( 
            /* [out] */ unsigned char **pFrame,
            /* [out] */ CHAR **pBitmapInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMinObjSize( 
            /* [in] */ LONG minSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMaxObjSize( 
            /* [in] */ LONG maxSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetBigwinShiftZoomAndRot( 
            /* [out] */ FLOAT *zoom,
            /* [out] */ FLOAT *zoom_center_x,
            /* [out] */ FLOAT *zoom_center_y,
            /* [out] */ FLOAT *rot,
            /* [out] */ FLOAT *shift_x,
            /* [out] */ FLOAT *shift_y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DrawVmdPathHistory( 
            /* [in] */ LONG drawHistory) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNoiseLevel( 
            /* [retval][out] */ float *noiseLevel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMinMotion( 
            /* [retval][out] */ LONG *minMotion) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFramesDelay( 
            /* [retval][out] */ LONG *framesDelay) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMinObjectSize( 
            /* [retval][out] */ LONG *minObjSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMaxObjectSize( 
            /* [retval][out] */ LONG *maxObjSize) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAntiTreeMode( 
            /* [in] */ LONG mode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteMaskObjectAsInt( 
            /* [in] */ LONGLONG maskObjPtr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSODCellSize( 
            /* [in] */ int x,
            /* [in] */ int y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSODFramesToDetectObjectCome( 
            /* [in] */ int frames) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSODStaticMinColorThreshold( 
            /* [in] */ int thresh) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSODColorThresholdFactor( 
            /* [in] */ float factor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSODBorderForDetection( 
            /* [in] */ int x,
            /* [in] */ int y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSODFramesToViewAlerts( 
            /* [in] */ int frames) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSODHistogramStackSize( 
            /* [in] */ int size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSODMinDetectionPreiodForObject( 
            /* [in] */ int preiod) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEvents( 
            /* [out] */ MovingObjectEventIDL **events,
            /* [out] */ int *size) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsCameraHidden( 
            /* [out] */ boolean *isHidden) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSODFramesToDetectObjectGone( 
            /* [in] */ int frames) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMinGroupCoverage( 
            /* [in] */ int coverage) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EnableVMD( 
            /* [in] */ boolean enable) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSODFramesToRemember( 
            /* [in] */ int frames) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetExternTransformation( 
            /* [in] */ BOOL accumulateTrans,
            /* [in] */ FLOAT mat00,
            /* [in] */ FLOAT mat01,
            /* [in] */ FLOAT mat02,
            /* [in] */ FLOAT mat10,
            /* [in] */ FLOAT mat11,
            /* [in] */ FLOAT mat12,
            /* [in] */ FLOAT mat20,
            /* [in] */ FLOAT mat21,
            /* [in] */ FLOAT mat22) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ResetStabilization( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLaplacianPyr( 
            /* [in] */ CHAR *lapImagesArray,
            /* [in] */ ULONG fromLevel,
            /* [in] */ ULONG toLevel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NextFrameWithVMDResults( 
            /* [in] */ unsigned char *image,
            /* [out] */ MovingObjectDataStructForIDL **detections_Array,
            /* [out] */ int *numObjects,
            /* [out] */ LONG *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTransForStabilization( 
            /* [out] */ FLOAT **transfForStabilization) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowBigWin( 
            /* [in] */ LONG show) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCameraCalibration( 
            /* [in] */ CHAR *CamCalibFileName,
            /* [retval][out] */ LONG *ResultFlag) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMinMaxDetectionSizeSpeedRange( 
            /* [in] */ double minSize,
            /* [in] */ double maxSize,
            /* [in] */ double minSpeed,
            /* [in] */ double maxSpeed,
            /* [in] */ double minRange,
            /* [in] */ double maxRange) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddMinMaxDetectionSizeSpeedRange( 
            /* [in] */ double minSize,
            /* [in] */ double maxSize,
            /* [in] */ double minSpeed,
            /* [in] */ double maxSpeed,
            /* [in] */ double minRange,
            /* [in] */ double maxRange) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetMinMaxImageResolution( 
            /* [in] */ double minResolution,
            /* [in] */ double maxResolution) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetResolutionGrid( 
            /* [in] */ int gridSizeX,
            /* [in] */ int gridSizeY,
            /* [in] */ double **minGrid,
            /* [in] */ double **maxGrid,
            /* [in] */ int gridBorderX1,
            /* [in] */ int gridBorderY1,
            /* [in] */ int gridBorderX2,
            /* [in] */ int gridBorderY2,
            int img_size_x,
            int img_size_y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetParallaxParams( 
            /* [in] */ double **imageTransformations,
            /* [in] */ double *imageToWorldTransformation,
            /* [in] */ double *world2ImageTransformation,
            /* [in] */ LONG matchingStatus,
            /* [in] */ int motionStatus,
            /* [in] */ int zArrayX,
            /* [in] */ int zArrayY,
            /* [in] */ double **minZ,
            /* [in] */ double **maxZ,
            /* [in] */ double *planeLoc,
            /* [in] */ double **groundHeightMin,
            /* [in] */ double **groundHeightMax) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVmdParameters( 
            /* [out] */ int *param1,
            /* [out] */ int *param2,
            /* [out] */ int *param3,
            /* [out] */ int **param4) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStacksStructure( 
            /* [out] */ int **stackStructure) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCurrentTimeInMilliSecond( 
            /* [in] */ long time) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetImageInformation( 
            /* [out] */ int *width,
            /* [out] */ int *height,
            /* [out] */ int *color_depth,
            /* [out] */ DWORD *compression) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StartStreaming( 
            /* [in] */ BSTR LocalIP,
            /* [in] */ UINT port,
            /* [in] */ BSTR videoName,
            /* [in] */ int Protocol,
            /* [in] */ int flipImage,
            /* [in] */ float scale) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopStreaming( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenRoiEditor( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetOpenDebugWindows( 
            int mode) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICStabVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICStab * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICStab * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICStab * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICStab * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICStab * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICStab * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICStab * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NextFrame )( 
            ICStab * This,
            /* [in] */ unsigned char *image,
            /* [retval][out] */ LONG *res);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MotionAdaptivity )( 
            ICStab * This,
            /* [retval][out] */ int *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MotionAdaptivity )( 
            ICStab * This,
            /* [in] */ int newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StrongStabRange )( 
            ICStab * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StrongStabRange )( 
            ICStab * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageSmoothFactor )( 
            ICStab * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImageSmoothFactor )( 
            ICStab * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageSharpFactor )( 
            ICStab * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImageSharpFactor )( 
            ICStab * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableImageEnhuncement )( 
            ICStab * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableImageEnhuncement )( 
            ICStab * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CameraModel )( 
            ICStab * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CameraModel )( 
            ICStab * This,
            /* [in] */ short newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            ICStab * This,
            /* [in] */ int image_size_x,
            /* [in] */ int image_size_y,
            /* [in] */ int color_channels,
            /* [in] */ int debug_mode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStabilizedImage )( 
            ICStab * This,
            /* [retval][out] */ unsigned char **image);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            ICStab * This,
            /* [retval][out] */ unsigned char **ver_str);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVersionStringAsInt )( 
            ICStab * This,
            /* [retval][out] */ LONGLONG *version);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStabilizedImageAsInt )( 
            ICStab * This,
            /* [retval][out] */ LONGLONG *image_pnt);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NextFrameByInt )( 
            ICStab * This,
            /* [in] */ int image);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetInputImageClipping )( 
            ICStab * This,
            /* [in] */ int left,
            /* [in] */ int top,
            /* [in] */ int right,
            /* [in] */ int bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetStabilizationRange )( 
            ICStab * This,
            /* [in] */ int x,
            /* [in] */ int y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetLastFrameTranslation )( 
            ICStab * This,
            /* [out] */ int *tx,
            /* [out] */ int *ty);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenPropertiesDialog )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitMotionDetection )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMovingObjectsArray )( 
            ICStab * This,
            /* [out] */ CHAR **array,
            /* [retval][out] */ int *array_size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMinMotion )( 
            ICStab * This,
            /* [in] */ int min_motion);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetNoiseLevel )( 
            ICStab * This,
            /* [in] */ double err_factor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetDetection )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DrawMovingObjects )( 
            ICStab * This,
            /* [in] */ int hdc,
            /* [in] */ int sx,
            /* [in] */ int sy);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetClippingForMotionDetection )( 
            ICStab * This,
            /* [in] */ int left,
            /* [in] */ int top,
            /* [in] */ int right,
            /* [in] */ int bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetClippingForStab )( 
            ICStab * This,
            /* [in] */ int left,
            /* [in] */ int top,
            /* [in] */ int right,
            /* [in] */ int bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMaskForVmd )( 
            ICStab * This,
            /* [in] */ CHAR *mask_obj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMaskForStab )( 
            ICStab * This,
            /* [in] */ CHAR *mask_obj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetRegionsOfInterestFileName )( 
            ICStab * This,
            /* [in] */ BSTR interestFileName,
            /* [retval][out] */ SHORT *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetFramesDelayForDetection )( 
            ICStab * This,
            /* [in] */ LONG framesDelay);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetNumOfSlowSkips )( 
            ICStab * This,
            /* [in] */ ULONG numOfSlowSkips);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsPlugOk )( 
            ICStab * This,
            /* [retval][out] */ SHORT *isOk);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UseParamFile )( 
            ICStab * This,
            /* [in] */ BSTR fname);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMovingObjectsArrayAsInt )( 
            ICStab * This,
            /* [out] */ LONGLONG *array,
            /* [retval][out] */ int *array_size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateTrackingObject )( 
            ICStab * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [retval][out] */ int *obj_id);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteTrackingObject )( 
            ICStab * This,
            /* [in] */ int obj_id);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitBigWin )( 
            ICStab * This,
            /* [in] */ LONG hwndForDrain,
            /* [in] */ LONG enableFullScreenMode,
            /* [in] */ int textureNum,
            /* [in] */ int textureNumForDisplay);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Init2 )( 
            ICStab * This,
            /* [in] */ int imageSizeX,
            /* [in] */ int imageSizeY,
            /* [in] */ int compression,
            /* [in] */ int bitPerPixel,
            /* [in] */ int topDownPic,
            /* [in] */ int YV12Frame,
            /* [in] */ int GrayResize,
            /* [in] */ int ColorResize,
            /* [in] */ int interlaceMode,
            /* [in] */ int interlaceResize,
            /* [in] */ int debug_mode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetD3dHwnd )( 
            ICStab * This,
            /* [retval][out] */ int *pHwnd);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowFpsAndStabInfoRect )( 
            ICStab * This,
            /* [in] */ LONG show);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DrawRegionsOfInterest )( 
            ICStab * This,
            /* [in] */ LONG hdc,
            /* [in] */ int flags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTransfFromLastFrame )( 
            ICStab * This,
            /* [retval][out] */ unsigned char **transf);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetUseStabInBigwin )( 
            ICStab * This,
            /* [in] */ LONG stab);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsBigWinDrawing )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTransfFromLastFrameAsInt )( 
            ICStab * This,
            /* [retval][out] */ int *transf);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitSOD )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DrawSOD )( 
            ICStab * This,
            /* [in] */ int hdc,
            /* [in] */ int sx,
            /* [in] */ int sy);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDetectionStatusSOD )( 
            ICStab * This,
            /* [out] */ BYTE *isDetected);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNextRectDetectionFromSOD )( 
            ICStab * This,
            /* [out] */ BYTE *isNew,
            /* [out] */ int *t,
            /* [out] */ int *l,
            /* [out] */ int *b,
            /* [out] */ int *r);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsInitSOD )( 
            ICStab * This,
            /* [out] */ BYTE *initFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearDetectionsSOD )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableSOD )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisableSOD )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *KillSOD )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *KillRegionsOfInterest )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableRegionsOfInterest )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DisableRegionsOfInterest )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateMaskFromBitMap )( 
            ICStab * This,
            /* [in] */ CHAR *bitMapInfoHeader,
            /* [in] */ CHAR *data,
            /* [in] */ UINT cellSizeX,
            /* [in] */ UINT cellSizeY,
            /* [retval][out] */ CHAR **maskClassObjPtr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteMaskObject )( 
            ICStab * This,
            /* [in] */ CHAR *maskObjPtr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMovingObjectsArrayIDLStruct )( 
            ICStab * This,
            /* [out] */ MovingObjectDataStructForIDL **detections_Array,
            /* [out] */ int *numObjects);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMovingObjectsArrayIDLStruct )( 
            ICStab * This,
            /* [in] */ MovingObjectDataStructForIDL *detections_Array,
            /* [in] */ int numObjects);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMovingObjectsArrayIDLStructINT )( 
            ICStab * This,
            /* [out] */ int *detections_Array,
            /* [out] */ int *numObjects);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowStabilizerControlWindow )( 
            ICStab * This,
            /* [in] */ LONG show);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetStabilizerVideoEnhancmentsValues )( 
            ICStab * This,
            /* [in] */ FLOAT noiseFilterVal,
            /* [in] */ FLOAT shapnessVal,
            /* [in] */ LONG brightnessVal,
            /* [in] */ FLOAT contrastVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStabilizerVideoEnhancmentsValues )( 
            ICStab * This,
            /* [out] */ FLOAT *noiseFilterVal,
            /* [out] */ FLOAT *shapnessVal,
            /* [out] */ LONG *brightnessVal,
            /* [out] */ FLOAT *contrastVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetDrawRecivedVmdPoligons )( 
            ICStab * This,
            /* [in] */ LONG display);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetUseStabInBigwin )( 
            ICStab * This,
            /* [out] */ LONG *stab);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateMaskFromBitMap2 )( 
            ICStab * This,
            /* [in] */ CHAR *fullfile,
            /* [in] */ ULONG cellSizeX,
            /* [in] */ ULONG cellSizeY,
            /* [retval][out] */ ULONG *maskClassObjPtr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateMaskFromBitMap2AsInt )( 
            ICStab * This,
            /* [in] */ LONGLONG fullfilePointer,
            /* [in] */ ULONG cellSizeX,
            /* [in] */ ULONG cellSizeY,
            /* [retval][out] */ ULONG *maskClassObjPtr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMaskForVmdAsInt )( 
            ICStab * This,
            /* [in] */ LONGLONG mask_obj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMaskForStabAsInt )( 
            ICStab * This,
            /* [in] */ LONGLONG mask_obj);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetBigwinShiftZoomAndRot )( 
            ICStab * This,
            /* [in] */ FLOAT zoom,
            /* [in] */ FLOAT zoom_center_x,
            /* [in] */ FLOAT zoom_center_y,
            /* [in] */ FLOAT rot,
            /* [in] */ FLOAT shift_x,
            /* [in] */ FLOAT shift_y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOverlayBitmaps )( 
            ICStab * This,
            /* [in] */ unsigned char *firstOverlayBitmap,
            /* [in] */ unsigned char *secondOverlayBitmap,
            /* [in] */ int sizeX,
            int sizeY,
            int bitPerPixel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DrawOverlayBitmaps )( 
            ICStab * This,
            /* [in] */ int drawOverly1,
            /* [in] */ int drawOverlay2,
            /* [in] */ int drawOrder);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FreezeBigWinImage )( 
            ICStab * This,
            /* [in] */ LONG freeze);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveBigWinFrameToMemory )( 
            ICStab * This,
            /* [in] */ LONG save);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSavedBigWinFrame )( 
            ICStab * This,
            /* [out] */ unsigned char **pFrame,
            /* [out] */ CHAR **pBitmapInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMinObjSize )( 
            ICStab * This,
            /* [in] */ LONG minSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMaxObjSize )( 
            ICStab * This,
            /* [in] */ LONG maxSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetBigwinShiftZoomAndRot )( 
            ICStab * This,
            /* [out] */ FLOAT *zoom,
            /* [out] */ FLOAT *zoom_center_x,
            /* [out] */ FLOAT *zoom_center_y,
            /* [out] */ FLOAT *rot,
            /* [out] */ FLOAT *shift_x,
            /* [out] */ FLOAT *shift_y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DrawVmdPathHistory )( 
            ICStab * This,
            /* [in] */ LONG drawHistory);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetNoiseLevel )( 
            ICStab * This,
            /* [retval][out] */ float *noiseLevel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMinMotion )( 
            ICStab * This,
            /* [retval][out] */ LONG *minMotion);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFramesDelay )( 
            ICStab * This,
            /* [retval][out] */ LONG *framesDelay);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMinObjectSize )( 
            ICStab * This,
            /* [retval][out] */ LONG *minObjSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetMaxObjectSize )( 
            ICStab * This,
            /* [retval][out] */ LONG *maxObjSize);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAntiTreeMode )( 
            ICStab * This,
            /* [in] */ LONG mode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteMaskObjectAsInt )( 
            ICStab * This,
            /* [in] */ LONGLONG maskObjPtr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSODCellSize )( 
            ICStab * This,
            /* [in] */ int x,
            /* [in] */ int y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSODFramesToDetectObjectCome )( 
            ICStab * This,
            /* [in] */ int frames);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSODStaticMinColorThreshold )( 
            ICStab * This,
            /* [in] */ int thresh);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSODColorThresholdFactor )( 
            ICStab * This,
            /* [in] */ float factor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSODBorderForDetection )( 
            ICStab * This,
            /* [in] */ int x,
            /* [in] */ int y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSODFramesToViewAlerts )( 
            ICStab * This,
            /* [in] */ int frames);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSODHistogramStackSize )( 
            ICStab * This,
            /* [in] */ int size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSODMinDetectionPreiodForObject )( 
            ICStab * This,
            /* [in] */ int preiod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetEvents )( 
            ICStab * This,
            /* [out] */ MovingObjectEventIDL **events,
            /* [out] */ int *size);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *IsCameraHidden )( 
            ICStab * This,
            /* [out] */ boolean *isHidden);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSODFramesToDetectObjectGone )( 
            ICStab * This,
            /* [in] */ int frames);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMinGroupCoverage )( 
            ICStab * This,
            /* [in] */ int coverage);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EnableVMD )( 
            ICStab * This,
            /* [in] */ boolean enable);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSODFramesToRemember )( 
            ICStab * This,
            /* [in] */ int frames);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetExternTransformation )( 
            ICStab * This,
            /* [in] */ BOOL accumulateTrans,
            /* [in] */ FLOAT mat00,
            /* [in] */ FLOAT mat01,
            /* [in] */ FLOAT mat02,
            /* [in] */ FLOAT mat10,
            /* [in] */ FLOAT mat11,
            /* [in] */ FLOAT mat12,
            /* [in] */ FLOAT mat20,
            /* [in] */ FLOAT mat21,
            /* [in] */ FLOAT mat22);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ResetStabilization )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetLaplacianPyr )( 
            ICStab * This,
            /* [in] */ CHAR *lapImagesArray,
            /* [in] */ ULONG fromLevel,
            /* [in] */ ULONG toLevel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NextFrameWithVMDResults )( 
            ICStab * This,
            /* [in] */ unsigned char *image,
            /* [out] */ MovingObjectDataStructForIDL **detections_Array,
            /* [out] */ int *numObjects,
            /* [out] */ LONG *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetTransForStabilization )( 
            ICStab * This,
            /* [out] */ FLOAT **transfForStabilization);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ShowBigWin )( 
            ICStab * This,
            /* [in] */ LONG show);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCameraCalibration )( 
            ICStab * This,
            /* [in] */ CHAR *CamCalibFileName,
            /* [retval][out] */ LONG *ResultFlag);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMinMaxDetectionSizeSpeedRange )( 
            ICStab * This,
            /* [in] */ double minSize,
            /* [in] */ double maxSize,
            /* [in] */ double minSpeed,
            /* [in] */ double maxSpeed,
            /* [in] */ double minRange,
            /* [in] */ double maxRange);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddMinMaxDetectionSizeSpeedRange )( 
            ICStab * This,
            /* [in] */ double minSize,
            /* [in] */ double maxSize,
            /* [in] */ double minSpeed,
            /* [in] */ double maxSpeed,
            /* [in] */ double minRange,
            /* [in] */ double maxRange);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetMinMaxImageResolution )( 
            ICStab * This,
            /* [in] */ double minResolution,
            /* [in] */ double maxResolution);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetResolutionGrid )( 
            ICStab * This,
            /* [in] */ int gridSizeX,
            /* [in] */ int gridSizeY,
            /* [in] */ double **minGrid,
            /* [in] */ double **maxGrid,
            /* [in] */ int gridBorderX1,
            /* [in] */ int gridBorderY1,
            /* [in] */ int gridBorderX2,
            /* [in] */ int gridBorderY2,
            int img_size_x,
            int img_size_y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetParallaxParams )( 
            ICStab * This,
            /* [in] */ double **imageTransformations,
            /* [in] */ double *imageToWorldTransformation,
            /* [in] */ double *world2ImageTransformation,
            /* [in] */ LONG matchingStatus,
            /* [in] */ int motionStatus,
            /* [in] */ int zArrayX,
            /* [in] */ int zArrayY,
            /* [in] */ double **minZ,
            /* [in] */ double **maxZ,
            /* [in] */ double *planeLoc,
            /* [in] */ double **groundHeightMin,
            /* [in] */ double **groundHeightMax);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetVmdParameters )( 
            ICStab * This,
            /* [out] */ int *param1,
            /* [out] */ int *param2,
            /* [out] */ int *param3,
            /* [out] */ int **param4);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetStacksStructure )( 
            ICStab * This,
            /* [out] */ int **stackStructure);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetCurrentTimeInMilliSecond )( 
            ICStab * This,
            /* [in] */ long time);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetImageInformation )( 
            ICStab * This,
            /* [out] */ int *width,
            /* [out] */ int *height,
            /* [out] */ int *color_depth,
            /* [out] */ DWORD *compression);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StartStreaming )( 
            ICStab * This,
            /* [in] */ BSTR LocalIP,
            /* [in] */ UINT port,
            /* [in] */ BSTR videoName,
            /* [in] */ int Protocol,
            /* [in] */ int flipImage,
            /* [in] */ float scale);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StopStreaming )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenRoiEditor )( 
            ICStab * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetOpenDebugWindows )( 
            ICStab * This,
            int mode);
        
        END_INTERFACE
    } ICStabVtbl;

    interface ICStab
    {
        CONST_VTBL struct ICStabVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICStab_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICStab_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICStab_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICStab_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICStab_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICStab_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICStab_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICStab_NextFrame(This,image,res)	\
    ( (This)->lpVtbl -> NextFrame(This,image,res) ) 

#define ICStab_get_MotionAdaptivity(This,pVal)	\
    ( (This)->lpVtbl -> get_MotionAdaptivity(This,pVal) ) 

#define ICStab_put_MotionAdaptivity(This,newVal)	\
    ( (This)->lpVtbl -> put_MotionAdaptivity(This,newVal) ) 

#define ICStab_get_StrongStabRange(This,pVal)	\
    ( (This)->lpVtbl -> get_StrongStabRange(This,pVal) ) 

#define ICStab_put_StrongStabRange(This,newVal)	\
    ( (This)->lpVtbl -> put_StrongStabRange(This,newVal) ) 

#define ICStab_get_ImageSmoothFactor(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageSmoothFactor(This,pVal) ) 

#define ICStab_put_ImageSmoothFactor(This,newVal)	\
    ( (This)->lpVtbl -> put_ImageSmoothFactor(This,newVal) ) 

#define ICStab_get_ImageSharpFactor(This,pVal)	\
    ( (This)->lpVtbl -> get_ImageSharpFactor(This,pVal) ) 

#define ICStab_put_ImageSharpFactor(This,newVal)	\
    ( (This)->lpVtbl -> put_ImageSharpFactor(This,newVal) ) 

#define ICStab_get_EnableImageEnhuncement(This,pVal)	\
    ( (This)->lpVtbl -> get_EnableImageEnhuncement(This,pVal) ) 

#define ICStab_put_EnableImageEnhuncement(This,newVal)	\
    ( (This)->lpVtbl -> put_EnableImageEnhuncement(This,newVal) ) 

#define ICStab_get_CameraModel(This,pVal)	\
    ( (This)->lpVtbl -> get_CameraModel(This,pVal) ) 

#define ICStab_put_CameraModel(This,newVal)	\
    ( (This)->lpVtbl -> put_CameraModel(This,newVal) ) 

#define ICStab_Init(This,image_size_x,image_size_y,color_channels,debug_mode)	\
    ( (This)->lpVtbl -> Init(This,image_size_x,image_size_y,color_channels,debug_mode) ) 

#define ICStab_GetStabilizedImage(This,image)	\
    ( (This)->lpVtbl -> GetStabilizedImage(This,image) ) 

#define ICStab_GetVersion(This,ver_str)	\
    ( (This)->lpVtbl -> GetVersion(This,ver_str) ) 

#define ICStab_GetVersionStringAsInt(This,version)	\
    ( (This)->lpVtbl -> GetVersionStringAsInt(This,version) ) 

#define ICStab_GetStabilizedImageAsInt(This,image_pnt)	\
    ( (This)->lpVtbl -> GetStabilizedImageAsInt(This,image_pnt) ) 

#define ICStab_NextFrameByInt(This,image)	\
    ( (This)->lpVtbl -> NextFrameByInt(This,image) ) 

#define ICStab_SetInputImageClipping(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> SetInputImageClipping(This,left,top,right,bottom) ) 

#define ICStab_SetStabilizationRange(This,x,y)	\
    ( (This)->lpVtbl -> SetStabilizationRange(This,x,y) ) 

#define ICStab_GetLastFrameTranslation(This,tx,ty)	\
    ( (This)->lpVtbl -> GetLastFrameTranslation(This,tx,ty) ) 

#define ICStab_OpenPropertiesDialog(This)	\
    ( (This)->lpVtbl -> OpenPropertiesDialog(This) ) 

#define ICStab_InitMotionDetection(This)	\
    ( (This)->lpVtbl -> InitMotionDetection(This) ) 

#define ICStab_GetMovingObjectsArray(This,array,array_size)	\
    ( (This)->lpVtbl -> GetMovingObjectsArray(This,array,array_size) ) 

#define ICStab_SetMinMotion(This,min_motion)	\
    ( (This)->lpVtbl -> SetMinMotion(This,min_motion) ) 

#define ICStab_SetNoiseLevel(This,err_factor)	\
    ( (This)->lpVtbl -> SetNoiseLevel(This,err_factor) ) 

#define ICStab_ResetDetection(This)	\
    ( (This)->lpVtbl -> ResetDetection(This) ) 

#define ICStab_DrawMovingObjects(This,hdc,sx,sy)	\
    ( (This)->lpVtbl -> DrawMovingObjects(This,hdc,sx,sy) ) 

#define ICStab_SetClippingForMotionDetection(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> SetClippingForMotionDetection(This,left,top,right,bottom) ) 

#define ICStab_SetClippingForStab(This,left,top,right,bottom)	\
    ( (This)->lpVtbl -> SetClippingForStab(This,left,top,right,bottom) ) 

#define ICStab_SetMaskForVmd(This,mask_obj)	\
    ( (This)->lpVtbl -> SetMaskForVmd(This,mask_obj) ) 

#define ICStab_SetMaskForStab(This,mask_obj)	\
    ( (This)->lpVtbl -> SetMaskForStab(This,mask_obj) ) 

#define ICStab_SetRegionsOfInterestFileName(This,interestFileName,res)	\
    ( (This)->lpVtbl -> SetRegionsOfInterestFileName(This,interestFileName,res) ) 

#define ICStab_SetFramesDelayForDetection(This,framesDelay)	\
    ( (This)->lpVtbl -> SetFramesDelayForDetection(This,framesDelay) ) 

#define ICStab_SetNumOfSlowSkips(This,numOfSlowSkips)	\
    ( (This)->lpVtbl -> SetNumOfSlowSkips(This,numOfSlowSkips) ) 

#define ICStab_IsPlugOk(This,isOk)	\
    ( (This)->lpVtbl -> IsPlugOk(This,isOk) ) 

#define ICStab_UseParamFile(This,fname)	\
    ( (This)->lpVtbl -> UseParamFile(This,fname) ) 

#define ICStab_GetMovingObjectsArrayAsInt(This,array,array_size)	\
    ( (This)->lpVtbl -> GetMovingObjectsArrayAsInt(This,array,array_size) ) 

#define ICStab_CreateTrackingObject(This,x,y,obj_id)	\
    ( (This)->lpVtbl -> CreateTrackingObject(This,x,y,obj_id) ) 

#define ICStab_DeleteTrackingObject(This,obj_id)	\
    ( (This)->lpVtbl -> DeleteTrackingObject(This,obj_id) ) 

#define ICStab_InitBigWin(This,hwndForDrain,enableFullScreenMode,textureNum,textureNumForDisplay)	\
    ( (This)->lpVtbl -> InitBigWin(This,hwndForDrain,enableFullScreenMode,textureNum,textureNumForDisplay) ) 

#define ICStab_Init2(This,imageSizeX,imageSizeY,compression,bitPerPixel,topDownPic,YV12Frame,GrayResize,ColorResize,interlaceMode,interlaceResize,debug_mode)	\
    ( (This)->lpVtbl -> Init2(This,imageSizeX,imageSizeY,compression,bitPerPixel,topDownPic,YV12Frame,GrayResize,ColorResize,interlaceMode,interlaceResize,debug_mode) ) 

#define ICStab_GetD3dHwnd(This,pHwnd)	\
    ( (This)->lpVtbl -> GetD3dHwnd(This,pHwnd) ) 

#define ICStab_ShowFpsAndStabInfoRect(This,show)	\
    ( (This)->lpVtbl -> ShowFpsAndStabInfoRect(This,show) ) 

#define ICStab_DrawRegionsOfInterest(This,hdc,flags)	\
    ( (This)->lpVtbl -> DrawRegionsOfInterest(This,hdc,flags) ) 

#define ICStab_GetTransfFromLastFrame(This,transf)	\
    ( (This)->lpVtbl -> GetTransfFromLastFrame(This,transf) ) 

#define ICStab_SetUseStabInBigwin(This,stab)	\
    ( (This)->lpVtbl -> SetUseStabInBigwin(This,stab) ) 

#define ICStab_IsBigWinDrawing(This)	\
    ( (This)->lpVtbl -> IsBigWinDrawing(This) ) 

#define ICStab_GetTransfFromLastFrameAsInt(This,transf)	\
    ( (This)->lpVtbl -> GetTransfFromLastFrameAsInt(This,transf) ) 

#define ICStab_InitSOD(This)	\
    ( (This)->lpVtbl -> InitSOD(This) ) 

#define ICStab_DrawSOD(This,hdc,sx,sy)	\
    ( (This)->lpVtbl -> DrawSOD(This,hdc,sx,sy) ) 

#define ICStab_GetDetectionStatusSOD(This,isDetected)	\
    ( (This)->lpVtbl -> GetDetectionStatusSOD(This,isDetected) ) 

#define ICStab_GetNextRectDetectionFromSOD(This,isNew,t,l,b,r)	\
    ( (This)->lpVtbl -> GetNextRectDetectionFromSOD(This,isNew,t,l,b,r) ) 

#define ICStab_IsInitSOD(This,initFlag)	\
    ( (This)->lpVtbl -> IsInitSOD(This,initFlag) ) 

#define ICStab_ClearDetectionsSOD(This)	\
    ( (This)->lpVtbl -> ClearDetectionsSOD(This) ) 

#define ICStab_EnableSOD(This)	\
    ( (This)->lpVtbl -> EnableSOD(This) ) 

#define ICStab_DisableSOD(This)	\
    ( (This)->lpVtbl -> DisableSOD(This) ) 

#define ICStab_KillSOD(This)	\
    ( (This)->lpVtbl -> KillSOD(This) ) 

#define ICStab_KillRegionsOfInterest(This)	\
    ( (This)->lpVtbl -> KillRegionsOfInterest(This) ) 

#define ICStab_EnableRegionsOfInterest(This)	\
    ( (This)->lpVtbl -> EnableRegionsOfInterest(This) ) 

#define ICStab_DisableRegionsOfInterest(This)	\
    ( (This)->lpVtbl -> DisableRegionsOfInterest(This) ) 

#define ICStab_CreateMaskFromBitMap(This,bitMapInfoHeader,data,cellSizeX,cellSizeY,maskClassObjPtr)	\
    ( (This)->lpVtbl -> CreateMaskFromBitMap(This,bitMapInfoHeader,data,cellSizeX,cellSizeY,maskClassObjPtr) ) 

#define ICStab_DeleteMaskObject(This,maskObjPtr)	\
    ( (This)->lpVtbl -> DeleteMaskObject(This,maskObjPtr) ) 

#define ICStab_GetMovingObjectsArrayIDLStruct(This,detections_Array,numObjects)	\
    ( (This)->lpVtbl -> GetMovingObjectsArrayIDLStruct(This,detections_Array,numObjects) ) 

#define ICStab_SetMovingObjectsArrayIDLStruct(This,detections_Array,numObjects)	\
    ( (This)->lpVtbl -> SetMovingObjectsArrayIDLStruct(This,detections_Array,numObjects) ) 

#define ICStab_GetMovingObjectsArrayIDLStructINT(This,detections_Array,numObjects)	\
    ( (This)->lpVtbl -> GetMovingObjectsArrayIDLStructINT(This,detections_Array,numObjects) ) 

#define ICStab_ShowStabilizerControlWindow(This,show)	\
    ( (This)->lpVtbl -> ShowStabilizerControlWindow(This,show) ) 

#define ICStab_SetStabilizerVideoEnhancmentsValues(This,noiseFilterVal,shapnessVal,brightnessVal,contrastVal)	\
    ( (This)->lpVtbl -> SetStabilizerVideoEnhancmentsValues(This,noiseFilterVal,shapnessVal,brightnessVal,contrastVal) ) 

#define ICStab_GetStabilizerVideoEnhancmentsValues(This,noiseFilterVal,shapnessVal,brightnessVal,contrastVal)	\
    ( (This)->lpVtbl -> GetStabilizerVideoEnhancmentsValues(This,noiseFilterVal,shapnessVal,brightnessVal,contrastVal) ) 

#define ICStab_SetDrawRecivedVmdPoligons(This,display)	\
    ( (This)->lpVtbl -> SetDrawRecivedVmdPoligons(This,display) ) 

#define ICStab_GetUseStabInBigwin(This,stab)	\
    ( (This)->lpVtbl -> GetUseStabInBigwin(This,stab) ) 

#define ICStab_CreateMaskFromBitMap2(This,fullfile,cellSizeX,cellSizeY,maskClassObjPtr)	\
    ( (This)->lpVtbl -> CreateMaskFromBitMap2(This,fullfile,cellSizeX,cellSizeY,maskClassObjPtr) ) 

#define ICStab_CreateMaskFromBitMap2AsInt(This,fullfilePointer,cellSizeX,cellSizeY,maskClassObjPtr)	\
    ( (This)->lpVtbl -> CreateMaskFromBitMap2AsInt(This,fullfilePointer,cellSizeX,cellSizeY,maskClassObjPtr) ) 

#define ICStab_SetMaskForVmdAsInt(This,mask_obj)	\
    ( (This)->lpVtbl -> SetMaskForVmdAsInt(This,mask_obj) ) 

#define ICStab_SetMaskForStabAsInt(This,mask_obj)	\
    ( (This)->lpVtbl -> SetMaskForStabAsInt(This,mask_obj) ) 

#define ICStab_SetBigwinShiftZoomAndRot(This,zoom,zoom_center_x,zoom_center_y,rot,shift_x,shift_y)	\
    ( (This)->lpVtbl -> SetBigwinShiftZoomAndRot(This,zoom,zoom_center_x,zoom_center_y,rot,shift_x,shift_y) ) 

#define ICStab_SetOverlayBitmaps(This,firstOverlayBitmap,secondOverlayBitmap,sizeX,sizeY,bitPerPixel)	\
    ( (This)->lpVtbl -> SetOverlayBitmaps(This,firstOverlayBitmap,secondOverlayBitmap,sizeX,sizeY,bitPerPixel) ) 

#define ICStab_DrawOverlayBitmaps(This,drawOverly1,drawOverlay2,drawOrder)	\
    ( (This)->lpVtbl -> DrawOverlayBitmaps(This,drawOverly1,drawOverlay2,drawOrder) ) 

#define ICStab_FreezeBigWinImage(This,freeze)	\
    ( (This)->lpVtbl -> FreezeBigWinImage(This,freeze) ) 

#define ICStab_SaveBigWinFrameToMemory(This,save)	\
    ( (This)->lpVtbl -> SaveBigWinFrameToMemory(This,save) ) 

#define ICStab_GetSavedBigWinFrame(This,pFrame,pBitmapInfo)	\
    ( (This)->lpVtbl -> GetSavedBigWinFrame(This,pFrame,pBitmapInfo) ) 

#define ICStab_SetMinObjSize(This,minSize)	\
    ( (This)->lpVtbl -> SetMinObjSize(This,minSize) ) 

#define ICStab_SetMaxObjSize(This,maxSize)	\
    ( (This)->lpVtbl -> SetMaxObjSize(This,maxSize) ) 

#define ICStab_GetBigwinShiftZoomAndRot(This,zoom,zoom_center_x,zoom_center_y,rot,shift_x,shift_y)	\
    ( (This)->lpVtbl -> GetBigwinShiftZoomAndRot(This,zoom,zoom_center_x,zoom_center_y,rot,shift_x,shift_y) ) 

#define ICStab_DrawVmdPathHistory(This,drawHistory)	\
    ( (This)->lpVtbl -> DrawVmdPathHistory(This,drawHistory) ) 

#define ICStab_GetNoiseLevel(This,noiseLevel)	\
    ( (This)->lpVtbl -> GetNoiseLevel(This,noiseLevel) ) 

#define ICStab_GetMinMotion(This,minMotion)	\
    ( (This)->lpVtbl -> GetMinMotion(This,minMotion) ) 

#define ICStab_GetFramesDelay(This,framesDelay)	\
    ( (This)->lpVtbl -> GetFramesDelay(This,framesDelay) ) 

#define ICStab_GetMinObjectSize(This,minObjSize)	\
    ( (This)->lpVtbl -> GetMinObjectSize(This,minObjSize) ) 

#define ICStab_GetMaxObjectSize(This,maxObjSize)	\
    ( (This)->lpVtbl -> GetMaxObjectSize(This,maxObjSize) ) 

#define ICStab_SetAntiTreeMode(This,mode)	\
    ( (This)->lpVtbl -> SetAntiTreeMode(This,mode) ) 

#define ICStab_DeleteMaskObjectAsInt(This,maskObjPtr)	\
    ( (This)->lpVtbl -> DeleteMaskObjectAsInt(This,maskObjPtr) ) 

#define ICStab_SetSODCellSize(This,x,y)	\
    ( (This)->lpVtbl -> SetSODCellSize(This,x,y) ) 

#define ICStab_SetSODFramesToDetectObjectCome(This,frames)	\
    ( (This)->lpVtbl -> SetSODFramesToDetectObjectCome(This,frames) ) 

#define ICStab_SetSODStaticMinColorThreshold(This,thresh)	\
    ( (This)->lpVtbl -> SetSODStaticMinColorThreshold(This,thresh) ) 

#define ICStab_SetSODColorThresholdFactor(This,factor)	\
    ( (This)->lpVtbl -> SetSODColorThresholdFactor(This,factor) ) 

#define ICStab_SetSODBorderForDetection(This,x,y)	\
    ( (This)->lpVtbl -> SetSODBorderForDetection(This,x,y) ) 

#define ICStab_SetSODFramesToViewAlerts(This,frames)	\
    ( (This)->lpVtbl -> SetSODFramesToViewAlerts(This,frames) ) 

#define ICStab_SetSODHistogramStackSize(This,size)	\
    ( (This)->lpVtbl -> SetSODHistogramStackSize(This,size) ) 

#define ICStab_SetSODMinDetectionPreiodForObject(This,preiod)	\
    ( (This)->lpVtbl -> SetSODMinDetectionPreiodForObject(This,preiod) ) 

#define ICStab_GetEvents(This,events,size)	\
    ( (This)->lpVtbl -> GetEvents(This,events,size) ) 

#define ICStab_IsCameraHidden(This,isHidden)	\
    ( (This)->lpVtbl -> IsCameraHidden(This,isHidden) ) 

#define ICStab_SetSODFramesToDetectObjectGone(This,frames)	\
    ( (This)->lpVtbl -> SetSODFramesToDetectObjectGone(This,frames) ) 

#define ICStab_SetMinGroupCoverage(This,coverage)	\
    ( (This)->lpVtbl -> SetMinGroupCoverage(This,coverage) ) 

#define ICStab_EnableVMD(This,enable)	\
    ( (This)->lpVtbl -> EnableVMD(This,enable) ) 

#define ICStab_SetSODFramesToRemember(This,frames)	\
    ( (This)->lpVtbl -> SetSODFramesToRemember(This,frames) ) 

#define ICStab_SetExternTransformation(This,accumulateTrans,mat00,mat01,mat02,mat10,mat11,mat12,mat20,mat21,mat22)	\
    ( (This)->lpVtbl -> SetExternTransformation(This,accumulateTrans,mat00,mat01,mat02,mat10,mat11,mat12,mat20,mat21,mat22) ) 

#define ICStab_ResetStabilization(This)	\
    ( (This)->lpVtbl -> ResetStabilization(This) ) 

#define ICStab_SetLaplacianPyr(This,lapImagesArray,fromLevel,toLevel)	\
    ( (This)->lpVtbl -> SetLaplacianPyr(This,lapImagesArray,fromLevel,toLevel) ) 

#define ICStab_NextFrameWithVMDResults(This,image,detections_Array,numObjects,res)	\
    ( (This)->lpVtbl -> NextFrameWithVMDResults(This,image,detections_Array,numObjects,res) ) 

#define ICStab_GetTransForStabilization(This,transfForStabilization)	\
    ( (This)->lpVtbl -> GetTransForStabilization(This,transfForStabilization) ) 

#define ICStab_ShowBigWin(This,show)	\
    ( (This)->lpVtbl -> ShowBigWin(This,show) ) 

#define ICStab_SetCameraCalibration(This,CamCalibFileName,ResultFlag)	\
    ( (This)->lpVtbl -> SetCameraCalibration(This,CamCalibFileName,ResultFlag) ) 

#define ICStab_SetMinMaxDetectionSizeSpeedRange(This,minSize,maxSize,minSpeed,maxSpeed,minRange,maxRange)	\
    ( (This)->lpVtbl -> SetMinMaxDetectionSizeSpeedRange(This,minSize,maxSize,minSpeed,maxSpeed,minRange,maxRange) ) 

#define ICStab_AddMinMaxDetectionSizeSpeedRange(This,minSize,maxSize,minSpeed,maxSpeed,minRange,maxRange)	\
    ( (This)->lpVtbl -> AddMinMaxDetectionSizeSpeedRange(This,minSize,maxSize,minSpeed,maxSpeed,minRange,maxRange) ) 

#define ICStab_SetMinMaxImageResolution(This,minResolution,maxResolution)	\
    ( (This)->lpVtbl -> SetMinMaxImageResolution(This,minResolution,maxResolution) ) 

#define ICStab_SetResolutionGrid(This,gridSizeX,gridSizeY,minGrid,maxGrid,gridBorderX1,gridBorderY1,gridBorderX2,gridBorderY2,img_size_x,img_size_y)	\
    ( (This)->lpVtbl -> SetResolutionGrid(This,gridSizeX,gridSizeY,minGrid,maxGrid,gridBorderX1,gridBorderY1,gridBorderX2,gridBorderY2,img_size_x,img_size_y) ) 

#define ICStab_SetParallaxParams(This,imageTransformations,imageToWorldTransformation,world2ImageTransformation,matchingStatus,motionStatus,zArrayX,zArrayY,minZ,maxZ,planeLoc,groundHeightMin,groundHeightMax)	\
    ( (This)->lpVtbl -> SetParallaxParams(This,imageTransformations,imageToWorldTransformation,world2ImageTransformation,matchingStatus,motionStatus,zArrayX,zArrayY,minZ,maxZ,planeLoc,groundHeightMin,groundHeightMax) ) 

#define ICStab_GetVmdParameters(This,param1,param2,param3,param4)	\
    ( (This)->lpVtbl -> GetVmdParameters(This,param1,param2,param3,param4) ) 

#define ICStab_GetStacksStructure(This,stackStructure)	\
    ( (This)->lpVtbl -> GetStacksStructure(This,stackStructure) ) 

#define ICStab_SetCurrentTimeInMilliSecond(This,time)	\
    ( (This)->lpVtbl -> SetCurrentTimeInMilliSecond(This,time) ) 

#define ICStab_GetImageInformation(This,width,height,color_depth,compression)	\
    ( (This)->lpVtbl -> GetImageInformation(This,width,height,color_depth,compression) ) 

#define ICStab_StartStreaming(This,LocalIP,port,videoName,Protocol,flipImage,scale)	\
    ( (This)->lpVtbl -> StartStreaming(This,LocalIP,port,videoName,Protocol,flipImage,scale) ) 

#define ICStab_StopStreaming(This)	\
    ( (This)->lpVtbl -> StopStreaming(This) ) 

#define ICStab_OpenRoiEditor(This)	\
    ( (This)->lpVtbl -> OpenRoiEditor(This) ) 

#define ICStab_SetOpenDebugWindows(This,mode)	\
    ( (This)->lpVtbl -> SetOpenDebugWindows(This,mode) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICStab_SetCurrentTimeInMilliSecond_Proxy( 
    ICStab * This,
    /* [in] */ long time);


void __RPC_STUB ICStab_SetCurrentTimeInMilliSecond_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICStab_GetImageInformation_Proxy( 
    ICStab * This,
    /* [out] */ int *width,
    /* [out] */ int *height,
    /* [out] */ int *color_depth,
    /* [out] */ DWORD *compression);


void __RPC_STUB ICStab_GetImageInformation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICStab_StartStreaming_Proxy( 
    ICStab * This,
    /* [in] */ BSTR LocalIP,
    /* [in] */ UINT port,
    /* [in] */ BSTR videoName,
    /* [in] */ int Protocol,
    /* [in] */ int flipImage,
    /* [in] */ float scale);


void __RPC_STUB ICStab_StartStreaming_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICStab_StopStreaming_Proxy( 
    ICStab * This);


void __RPC_STUB ICStab_StopStreaming_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICStab_OpenRoiEditor_Proxy( 
    ICStab * This);


void __RPC_STUB ICStab_OpenRoiEditor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICStab_SetOpenDebugWindows_Proxy( 
    ICStab * This,
    int mode);


void __RPC_STUB ICStab_SetOpenDebugWindows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICStab_INTERFACE_DEFINED__ */



#ifndef __STABCOMWARPERLib_LIBRARY_DEFINED__
#define __STABCOMWARPERLib_LIBRARY_DEFINED__

/* library STABCOMWARPERLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_STABCOMWARPERLib;

#ifndef ___ICStabEvents_DISPINTERFACE_DEFINED__
#define ___ICStabEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ICStabEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ICStabEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0779B91F-7F73-42F7-9459-667EC65D5659")
    _ICStabEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ICStabEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ICStabEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ICStabEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ICStabEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ICStabEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ICStabEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ICStabEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ICStabEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _ICStabEventsVtbl;

    interface _ICStabEvents
    {
        CONST_VTBL struct _ICStabEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ICStabEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ICStabEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ICStabEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ICStabEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ICStabEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ICStabEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ICStabEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ICStabEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CStab;

#ifdef __cplusplus

class DECLSPEC_UUID("D0BE72D2-0B2F-4A5B-93B7-6A60DA55A14B")
CStab;
#endif

EXTERN_C const CLSID CLSID_FilterSetup;

#ifdef __cplusplus

class DECLSPEC_UUID("7E393810-256B-4B00-BA92-5FB5B2D79775")
FilterSetup;
#endif
#endif /* __STABCOMWARPERLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


