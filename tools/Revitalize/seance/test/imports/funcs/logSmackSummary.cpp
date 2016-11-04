{
  int *metricsa; // ST18_4@1

  metricsa = metrics;
  sprintf(globBuf, "                                              Name - %s", &aH2intro[45 * byte_524EC0]);
  debugLog(globBuf);
  sprintf(globBuf, "                                        total time - %8d", *metricsa);
  debugLog(globBuf);
  sprintf(globBuf, "MS*100 per frame (100000/MS100PerFrame=Frames/Sec) - %8d", metricsa[1]);
  debugLog(globBuf);
  sprintf(globBuf, "        Time to open and prepare for decompression - %8d", metricsa[2]);
  debugLog(globBuf);
  sprintf(globBuf, "                            Total Frames displayed - %8d", metricsa[3]);
  debugLog(globBuf);
  sprintf(globBuf, "                    Total number of skipped frames - %8d", metricsa[4]);
  debugLog(globBuf);
  sprintf(globBuf, "                         Total time spent blitting - %8d", metricsa[6]);
  debugLog(globBuf);
  sprintf(globBuf, "                          Total time spent reading - %8d", metricsa[7]);
  debugLog(globBuf);
  sprintf(globBuf, "                    Total time spent decompressing - %8d", metricsa[8]);
  debugLog(globBuf);
  sprintf(globBuf, "                     Total io speed (sbytes/second) - %8d", metricsa[10]);
  debugLog(globBuf);
  sprintf(globBuf, "                         Slowest single frame time - %8d", metricsa[11]);
  debugLog(globBuf);
  sprintf(globBuf, "                  Second slowest single frame time - %8d", metricsa[12]);
  debugLog(globBuf);
  sprintf(globBuf, "                       Slowest single frame number - %8d", metricsa[13]);
  debugLog(globBuf);
  sprintf(globBuf, "                Second slowest single frame number - %8d", metricsa[14]);
  debugLog(globBuf);
  sprintf(globBuf, "                         Average size of the frame - %8d", metricsa[15]);
  debugLog(globBuf);
  sprintf(globBuf, "                Highest amount of memory allocated - %8d", metricsa[16]);
  debugLog(globBuf);
}
