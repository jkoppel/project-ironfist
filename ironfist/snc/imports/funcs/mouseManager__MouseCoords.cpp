{
  GetCursorPos(&retrieveVirtualCursorCoordinates_lppoint);
  ScreenToClient(hwndApp, &retrieveVirtualCursorCoordinates_lppoint);
  *x = 640 * retrieveVirtualCursorCoordinates_lppoint.x / iMainWinScreenWidth;
  *y = 480 * retrieveVirtualCursorCoordinates_lppoint.y / iMainWinScreenHeight;
}