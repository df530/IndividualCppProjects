/***************************************************************
* Copyright (C) 2018
*    Computer Graphics Support Group of 30 Phys-Math Lyceum
***************************************************************/

/* FILE NAME    : WIN.H
 * PURPOSE      : WinAPI support.
 *                Window class declaration module.
 * PROGRAMMER   : CGSG'2018.
 *                Filippov Denis.
 * LAST UPDATE  : 23.07.2018.
 * NOTE         : None.
 *
 * No part of this file may be changed without agreement of
 * Computer Graphics Support Group of 30 Phys-Math Lyceum.
 */

#ifndef __WIN_H_
#define __WIN_H_

#include "def.h"

/* Animation project namespace */
namespace figl
{
  /* Windows class declaration */
  class win
  {
  protected:
    BOOL IsInit;                                             // Initialization flag
    BOOL IsFullScreen;                                       // Full screen flag
    WNDCLASS wc;                                             // Window class
    HWND hWnd;                                               // Window handle
    INT FrameW, FrameH;                                      // Window size
    static const INT TimerInitId = 11, TimerRefreshId = 78;  // Timer initialization and refresh identifiers
    INT MouseWheel;                                          // Global mouse window delta value
    HINSTANCE hInstance;                                     // Application handle
  
  private:
    /* Window message handle function (CALLBACK version).
     * ARGUMENTS:
     *   - window handle:
     *       HWND hWnd;
     *   - message identifier:
     *       UINT Msg;
     *   - message first parameter ('word' param):
     *       WPARAM wParam;
     *   - message second parameter ('long' param):
     *       LPARAM lParam;
     * RETURNS:
     *   (LRESULT) message return code (depended to Msg type).
     */
    static LRESULT CALLBACK WinFunc( HWND hWnd, UINT Msg,
      WPARAM wParam, LPARAM lParam );
  
  public:
    BOOL IsActive;  // Activation flag

    /* Win class constructor.
     * ARGUMENTS:
     *   - aplication handle:
     *       HINSTANCE hInst;
     */
    win( HINSTANCE hInst = GetModuleHandle(NULL) );
  
    /* Win class destructor.
    * ARGUMENTS: None.
    */
    ~win( VOID );
  
    /* Window run function.
     * ARGUMENTS: None.
     * RETURNS:None.
     */
    VOID Run( VOID );
  
    /* Flip Full screen function.
     * ARGUMENTS: None.
     * RETURNS: None.
     */
    VOID FlipFullScreen( VOID );
  
    // message cracks
    /* WM_CREATE window message handle function.
     * ARGUMENTS:
     *   - structure with creation data:
     *       CREATESTRUCT *CS;
     * RETURNS:
     *   (BOOL) TRUE to continue creation window, FALSE to terminate.
     */
    BOOL OnCreate( CREATESTRUCT *CS );
  
    /* WM_SIZE window message handle function.
     * ARGUMENTS:
     *   - sizing flag (see SIZE_***, like SIZE_MAXIMIZED)
     *       UINT State;
     *   - new width and height of client area:
     *       INT W, H;
     * RETURNS: None.
     */
    VOID OnSize( UINT State, INT W, INT H );
  
    /* WM_TIMER window message handle function.
     * ARGUMENTS:
     *   - specified the timer identifier:
     *       INT Id;
     * RETURNS: None.
     */
    VOID OnTimer( INT Id );
  
    /* WM_MOUSEWHEEL window message handle function.
    * ARGUMENTS:
    *   - mouse window position:
    *       INT X, Y;
    *   - mouse wheel relative delta value:
    *       INT Z;
    *   - mouse keys bits (see MK_*** bits constants):
    *       UINT Keys;
    * RETURNS: None.
    */
    VOID OnMouseWheel( INT X, INT Y, INT Z, UINT Keys );
  
    /* WM_ERASEBKGND window message handle function.
    * ARGUMENTS:
    *   - device context of client area:
    *       HDC hDC;
    * RETURNS:
    *   (BOOL) TRUE if background is erased, FALSE otherwise.
    */
    BOOL OnEraseBckgrnd( HDC hDC );
  
    /* WM_PAINT window message handle function.
    * ARGUMENTS: None.
    * RETURNS: None.
    */
    VOID OnPaint( VOID );
  
    /* WM_CLOSE window message handle funciton.
     * ARGUMENTS: None.
     */
    VOID OnClose( VOID );
  
    /* WM_DESTROY window message handle function.
    * ARGUMENTS: None.
    * RETURNS: None.
    */
    VOID OnDestroy( VOID );
  
    /* WM_ACTIVATE window message handle function.
     * ARGUMENTS:
     *   - reason (WA_CLICKACTIVE, WA_ACTIVE or WA_INACTIVE):
     *       UINT Reason;
     *   - handle of active window:
     *       HWND hWndActDeact;
     *   - minimized flag:
     *       BOOL IsMinimized;
     * RETURNS: None.
     */
    VOID OnActivate( UINT Reason, HWND hWndActDeact, BOOL IsMinimized );

     /***
     * Virtual functions for window customization
     ***/

    /* Initialization function.
     * ARGUMENTS: None.
     * RETURNS: None.
     */
    virtual VOID Init( VOID )
    {
    } /* End of 'Init' function */

    /* Deinitialization function.
     * ARGUMENTS: None.
     * RETURNS: None.
     */
    virtual VOID Close( VOID )
    {
    } /* End of 'Close' function */

    /* Change window size handle function.
     * ARGUMENTS: None.
     * RETURNS: None.
     */
    virtual VOID Resize( VOID )
    {
    } /* End of 'Resize' function */

    /* Erase background handle function.
     * ARGUMENTS:
     *   - device context of client area:
     *       HDC hDC;
     * RETURNS: None.
     */
    virtual VOID Erase( HDC hDC )
    {
    } /* End of 'Erase' function */

    /* Paint window content function.
     * ARGUMENTS:
     *   - device context of client area:
     *       HDC hDC;
     * RETURNS: None.
     */
    virtual VOID Paint( HDC hDC )
    {
    } /* End of 'Paint' function */

    /* Timer handle function.
     * ARGUMENTS: None.
     * RETURNS: None.
     */
    virtual VOID Timer( VOID )
    {
    } /* End of 'Timer' function */

    /* Activate handle function.
     * ARGUMENTS:
     *   - activation window flag:
     *       BOOL IsActive;
     * RETURNS: None.
     */
    virtual VOID Activate( BOOL IsActive )
    {
    } /* End of 'Activate' function */

    /* Free CPU time handling function.
     * ARGUMENTS: None.
     * RETURNS: None.
     */
    virtual VOID Idle( VOID )
    {
    } /* End of 'Idle' function */
  }; /* End of 'win' class */
} /* end of 'figl' namespace */
#endif /* __WIN_H_ */

/* END OF 'WIN.H' FILE */
