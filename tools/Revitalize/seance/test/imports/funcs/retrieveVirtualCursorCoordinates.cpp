{
  GetCursorPos(&retrieveVirtualCursorCoordinates_lppoint);
  ScreenToClient(windowHandle, &retrieveVirtualCursorCoordinates_lppoint);
  *x = 640 * retrieveVirtualCursorCoordinates_lppoint.x / couldBeScreenWidth;
  *y = 480 * retrieveVirtualCursorCoordinates_lppoint.y / couldBeScreenHeight;
}
