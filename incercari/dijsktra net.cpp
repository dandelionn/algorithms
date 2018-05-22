void dijkstra(int x0)
{
    //declaratii variabile:
    int i, j, min, k, ok;
    int viz[NMAX], d[NMAX], tata[NMAX];

    //initializari variabile:
    for (i = 1; i<=n; i++) {
        d[i] = C[x0][i];
        tata[i] = x0;
        viz[i] = 0;
    }
    tata[x0] = 0;
    viz[x0] = 1; ok = 1;

    //cautare distanta minima:

    while (ok)
         {
              //cautare distanta minima
              min = INFINIT;
              for (i = 1; i<=n; i++)                 //cautare distanta minima
                  if (!viz[i] && min>d[i])
                      {
                          min = d[i];                    //cautare distanta minima
                          k = i;                        //cautare distanta minima
                      }
        //actualizare distante:
        if (min != INFINIT)
             {
                  viz[k] = 1;
                  for (i = 1; i<=n; i++)
                      if (!viz[i] && d[i]>d[k]+C[k][i])
                          {
                          d[i] = d[k]+C[k][i];
                          tata[i] = k;
                          }
             }
        else ok = 0;
    }
}

void drum (int x) {
    int i, n = 0, traseu[NMAX];
    while (tata[x]) {
        traseu[++n] = x; x=tata[x];
    }
    traseu[++n]=x;
    for (i = 1; i <= n; i++)
        cout<<traseu[i]<<" ";
    cout<<"\n";
}

























int bellman_ford(int x0)
{
    //declaratii variabile
   int ok, i, j, k;

   //initializari variabile
   for (i=1;i<=n;i++) {
      tata[i] = 0; d[i] = INF;}
   d[x0] = 0;

   for (i=1; i<=n; i++)
   {
      ok = 0;
      //minimizare distante
      for (j=1;j<=n;j++)
         for (k=1;k<=n;k++)
            if (d[j]!=INF && c[j][k]!=INF)
               if (d[k]>d[j]+c[j][k])
               {
                  d[k] = d[j]+c[j][k];
                  tata[k] = j;
                  ok = 1;
               }
   }
   if (ok == 1) cout<<"Circuit negativ!";
   return ok;
}
