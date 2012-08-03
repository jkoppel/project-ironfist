{
  int *metricsa; // ST18_4@1

  metricsa = metrics;
  sprintf(gText, "                                              Name - %s", &SmackOptions[45 * bSmackNum]);
  LogStr(gText);
  sprintf(gText, "                                        total time - %8d", *metricsa);
  LogStr(gText);
  sprintf(gText, "MS*100 per frame (100000/MS100PerFrame=Frames/Sec) - %8d", metricsa[1]);
  LogStr(gText);
  sprintf(gText, "        Time to open and prepare for decompression - %8d", metricsa[2]);
  LogStr(gText);
  sprintf(gText, "                            Total Frames displayed - %8d", metricsa[3]);
  LogStr(gText);
  sprintf(gText, "                    Total number of skipped frames - %8d", metricsa[4]);
  LogStr(gText);
  sprintf(gText, "                         Total time spent blitting - %8d", metricsa[6]);
  LogStr(gText);
  sprintf(gText, "                          Total time spent reading - %8d", metricsa[7]);
  LogStr(gText);
  sprintf(gText, "                    Total time spent decompressing - %8d", metricsa[8]);
  LogStr(gText);
  sprintf(gText, "                     Total io speed (sbytes/second) - %8d", metricsa[10]);
  LogStr(gText);
  sprintf(gText, "                         Slowest single frame time - %8d", metricsa[11]);
  LogStr(gText);
  sprintf(gText, "                  Second slowest single frame time - %8d", metricsa[12]);
  LogStr(gText);
  sprintf(gText, "                       Slowest single frame number - %8d", metricsa[13]);
  LogStr(gText);
  sprintf(gText, "                Second slowest single frame number - %8d", metricsa[14]);
  LogStr(gText);
  sprintf(gText, "                         Average size of the frame - %8d", metricsa[15]);
  LogStr(gText);
  sprintf(gText, "                Highest amount of memory allocated - %8d", metricsa[16]);
  LogStr(gText);
}