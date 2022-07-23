int bouncingBall(double h, double bounce, double window) {
    if (!(h > 0 && (bounce > 0 && bounce < 1) && window < h))
      return -1;
    else
    {
      int t = 0;
      while (h > window)
      {
        h *= bounce;
        
        if (h > window)
          t++;
        t++;
      }
      return t;
    }
}
