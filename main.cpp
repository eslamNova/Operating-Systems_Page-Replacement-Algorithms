/* student name: islam ashraf ismail
    id: 017
    sec: 1 */







#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int LRU_min(int lru[],int f)
{
    int minimum = lru[0];
    int pos = 0;
    for(int i=0;i<f;i++) { if(minimum > lru[i])
           {   minimum = lru[i];
               pos = i;
           }
    }
 return pos;
}
int MRU_max(int mru[],int f)
{
    int maximum = mru[0];
    int pos = 0;
    for(int i=0;i<f;i++) { if(maximum < mru[i])
           {   maximum = mru[i];
               pos = i;
           }
    }
 return pos;
}

int LFU_min(int seq[],int frames[],int f,int lfu[],int p,int c_seq)
{
    int pos = 0 , minimum=99 ;
    for(int i=0;i<p;i++)
        { if((lfu[i]!=0)&&(minimum > lfu[i]))
           {
               minimum = i;
           }
        }
    for(int j = 0 ; j < c_seq ; j++)
    {
        if (lfu[minimum]==lfu[j])
        {
            for (int k = 0 ; k < f ; k ++)
            {
                for (int m = 0 ;  m<c_seq; m++)
                {
                    if(frames[k]==seq[m])
                    {
                        minimum=seq[m];
                    }
                    break;
                }


            }

        }
    }
    return minimum;
}

int MFU_min(int seq[],int frames[],int f,int lfu[],int p,int c_seq)
{
    int pos = 0 , minimum=99 ;
    for(int i=0;i<p;i++)
        { if((lfu[i]!=0)&&(minimum > lfu[i]))
           {
               minimum = i;
           }
        }
    for(int j = 0 ; j < c_seq ; j++)
    {
        if (lfu[minimum]==lfu[j])
        {
            for (int k = 0 ; k < f ; k ++)
            {
                for (int m = 0 ;  m<c_seq; m++)
                {
                    if(frames[k]==seq[m])
                    {
                        minimum=seq[m];
                    }
                    break;
                }


            }

        }
    }
    return minimum;
}


int main(){
    int f,p,s,c,sr,miss=0;
    int i,j,k,l,m;
    cout<<"enter number of frames: \n";
    cin>>f;
    cout<<"enter highest page number: \n";
    cin>>p;
    cout<<"enter length of sequence: \n";
    cin>>s;
    cout<<"enter srand number: \n";
    cin>>sr;
    cout<<"choose method:\n";
    cout<<"enter 777 to get all algorithms :D\n";
    cout<<"1 : FIFO \n2 : LRU\n3 : LFU\n4 : MFU\n5 : Optimum\n6 : Second Chance\n7 : MRU\n";
    cin>>c;

    int* seq = new int[s];
    int* frames = new int[f];
    int* lru = new int[f];
    int* mru = new int[f];
    int* secChance = new int[f];
    int* lfu = new int [p];
    int* mfu = new int [p];
    int* opt = new int[f];
    int* seq_lfu = new int[s];

    srand(sr);
    for (i=0 ; i<s ; i++)
    {
        seq[i]=rand()%p;
    }
    for (i=0;i<p;i++)
    {
        lfu[i]=0;
        mfu[i]=0;
    }

    cout<<"Your sequence is: \n";
        for(i=0;i<s;i++)
        {
            cout<<seq[i]<<"\t";
        }
    cout<<"\n";

    //methods
    ////////////////////////////////////////////////////////////////////////////////////////
    if(c==1||c==777)
    {
        cout<<"***FIFO ALGORITHM*** \n";
        int found=0 , miss=0;
        for(i=0 ; i <f ;i++)
        {
            frames[i]=-1;
        }
        cout<<"Sequence \t Frames \n";
        j=0;
        for(i=0;i<s;i++)
        {
            cout<<seq[i]<<"\t\t";
            found =0 ;
            for(k=0;k<f;k++)
            {
                if(frames[k]==seq[i])
                {
                    found=1;
                }
            }
            if(found==0)
            {
                frames[j]=seq[i];
                j = (j+1)%f;
                miss++;
                for(k=0;k<f;k++)
                {
                    cout<<frames[k]<<"\t";
                }

            }
            cout<<"\n";


        }
        cout<<"\n"<<"Total miss = "<<miss<<"\n";
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    if(c==2||c==777)
    {
        cout<<"***LRU ALGORITHM*** \n";
        int found =0 ,recent=0 ,miss =0 ;
        for(i=0 ; i <f ;i++)
        {
            frames[i]=-1;
            lru[i]=-1;
        }
        cout<<"Sequence \t Frames \n";
        for(i=0;i<s;i++)
        {
            cout<<seq[i]<<"\t\t";
            found =0 ;
            //*********
            for(k=0;k<f;k++)
            {
                if(frames[k]==seq[i])
                {
                    found=1;
                    lru[k]=recent++;
                    break;
                }
            }

            if(found==0)
            {
                for(j=0;j<f;j++)
                {
                    if(frames[j]==-1)
                    {
                        frames[j]=seq[i];
                        found=1;
                        lru[j]=recent++;
                        miss++;
                        for(k=0;k<f;k++)
                        {
                        cout<<frames[k]<<"\t";
                        }
                        break;
                    }

                }
            }
            if(found==0)
            {
                int lru_page = LRU_min(lru,f);
                frames[lru_page]=seq[i];
                lru[lru_page]=recent++;
                miss++;
                for(k=0;k<f;k++)
                {
                cout<<frames[k]<<"\t";
                }
            }
            cout<<"\n";


        }
        cout<<"\n"<<"Total miss = "<<miss<<"\n";

    }
    ////////////////////////////////////////////////////////////////////////////////////////
    if(c==7||c==777)
    {
        cout<<"***MRU ALGORITHM*** \n";
        int found =0 ,recent=0 ,miss =0 ;
        for(i=0 ; i <f ;i++)
        {
            frames[i]=-1;
            mru[i]=-1;
        }
        cout<<"Sequence \t Frames \n";
        for(i=0;i<s;i++)
        {
            cout<<seq[i]<<"\t\t";
            found =0 ;
            //*********
            for(k=0;k<f;k++)
            {
                if(frames[k]==seq[i])
                {
                    found=1;
                    mru[k]=recent++;
                    break;
                }
            }

            if(found==0)
            {
                for(j=0;j<f;j++)
                {
                    if(frames[j]==-1)
                    {
                        frames[j]=seq[i];
                        found=1;
                        mru[j]=recent++;
                        miss++;
                        for(k=0;k<f;k++)
                        {
                        cout<<frames[k]<<"\t";
                        }
                        break;
                    }

                }
            }
            if(found==0)
            {
                int mru_page = MRU_max(mru,f);
                frames[mru_page]=seq[i];
                mru[mru_page]=recent++;
                miss++;
                for(k=0;k<f;k++)
                {
                cout<<frames[k]<<"\t";
                }
            }
            cout<<"\n";


        }
        cout<<"\n"<<"Total miss = "<<miss<<"\n";

    }
    ////////////////////////////////////////////////////////////////////////////////////////
    if(c==3||c==777)
    {
        cout<<"***LFU ALGORITHM*** \n";
       int found=0 , recent=0, miss=0 ;
        for(i=0 ; i <f ;i++)
        {
            frames[i]=-1;
        }
        cout<<"Sequence \t Frames \n";
        for(i=0;i<s;i++)
        {
            cout<<seq[i]<<"\t\t";
            found =0 ;
            //*********
            for(k=0;k<f;k++)
            {
                if(frames[k]==seq[i])
                {
                    found=1;
                    lfu[seq[i]]=lfu[seq[i]] +1;


                    break;
                }
            }

            if(found==0)
            {
                for(j=0;j<f;j++)
                {
                    if(frames[j]==-1)
                    {
                        frames[j]=seq[i];
                        found=1;
                        lfu[seq[i]]=lfu[seq[i]] +1;


                        miss++;
                        for(k=0;k<f;k++)
                        {
                        cout<<frames[k]<<"\t";
                        }
                        break;
                    }

                }


            }
            if(found==0)
            {
                int lfu_pos ;
                int lfu_page = LFU_min(seq,frames,f,lfu,p,i);

                for (l=0;l<f ; l++)
                {
                    if(frames[l]==lfu_page)
                    {
                         lfu_pos = l;
                    }
                    break;
                }
                frames[lfu_pos]=seq[i];
                lfu[seq[i]] = lfu[seq[i]]+1;

                miss++;
                for(k=0;k<f;k++)
                {
                cout<<frames[k]<<"\t";
                }

            }

            cout<<"\n";
        }

        cout<<"\n"<<"Total miss = "<<miss<<"\n";
    }

    if(c==4||c==777)
    {
        cout<<"***MFU ALGORITHM*** \n";
        int found=0 , recent=0, miss=0 ;
        for(i=0 ; i <f ;i++)
        {
            frames[i]=-1;
        }
        cout<<"Sequence \t Frames \n";
        for(i=0;i<s;i++)
        {
            cout<<seq[i]<<"\t\t";
            found =0 ;
            //*********
            for(k=0;k<f;k++)
            {
                if(frames[k]==seq[i])
                {
                    found=1;
                    mfu[seq[i]]=mfu[seq[i]] +1;


                    break;
                }
            }

            if(found==0)
            {
                for(j=0;j<f;j++)
                {
                    if(frames[j]==-1)
                    {
                        frames[j]=seq[i];
                        found=1;
                        lfu[seq[i]]=lfu[seq[i]] +1;


                        miss++;
                        for(k=0;k<f;k++)
                        {
                        cout<<frames[k]<<"\t";
                        }
                        break;
                    }

                }


            }
            if(found==0)
            {
                int mfu_pos ;
                int mfu_page = MFU_min(seq,frames,f,lfu,p,i);

                for (l=0;l<f ; l++)
                {
                    if(frames[l]==mfu_page)
                    {
                         mfu_pos = l;
                    }
                    break;
                }
                frames[mfu_pos]=seq[i];
                lfu[seq[i]] = mfu[seq[i]]+1;

                miss++;
                for(k=0;k<f;k++)
                {
                cout<<frames[k]<<"\t";
                }

            }

            cout<<"\n";
        }

        cout<<"\n"<<"Total miss = "<<miss<<"\n";

    }
    //////////////////////////////////////////////////////////////////////////////////////
    if(c==5||c==777)
    {
        cout<<"***OPTIMUM ALGORITHM*** \n";
        int flag1=0 , flag2=0 , flag3=0 , miss=0,pos,max;
        for(i=0;i<f;i++)
        {
            frames[i]=-1;
        }
        cout<<"Sequence \t Frames \n";
        //*****
        for(i=0;i<s;i++)
        {
            cout<<seq[i]<<"\t\t";
            for(j=0;j<f;j++)
            {
                if(frames[j]==seq[i])
                {
                    flag1=flag2=flag3=1;
                    break;
                }
            }
            if(flag1==0)
            {
                for(j=0;j<f;j++)
                {
                    if(frames[j]==-1)
                    {
                        frames[j]=seq[i];
                        miss++;
                        flag2=flag3=1;
                        for(k=0;k<f;k++)
                        {
                            cout<<frames[k]<<"\t";
                        }
                        break;
                    }
                }
            }

            if(flag2==0)
            {
                for(j=0;j<f;j++)
                {
                    opt[j]=-1;

                    for(k=i+1;k<s;k++)

                        if(frames[j]==seq[k])
                        {
                            opt[j]=k;
                            break;
                        }
                }
                for(j=0;j<f;j++)
                {
                    if(opt[j]==-1)
                    {
                        pos=j;
                        flag3=1;
                        break;
                    }
                }
                if(flag3==0)
                {
                    max=opt[0];
                    for(k=1;k<f;k++)
                    {
                        if(opt[k]>max)
                        {
                            max=opt[k];
                            pos=k;
                            break;
                        }
                    }
                }
                frames[pos]=seq[i];
                miss++;
                for(k=0;k<f;k++)
                {
                    cout<<frames[k]<<"\t";
                }
                break;
            }
            cout<<"\n";
        }
    cout<<"\n"<<"Total miss = "<<miss<<"\n";

    }
    ////////////////////////////////////////////////////////////////////////////////////////
    if(c==6||c==777)
    {
        cout<<"***Second Chance ALGORITHM*** \n";
        int found=0 , miss=0;
        for(i=0 ; i <f ;i++)
        {
            frames[i]=-1;
            secChance[i]=0;
        }
        cout<<"Sequence \t Frames \n";
        j=0;
        for(i=0;i<s;i++)
        {
            cout<<seq[i]<<"\t\t";
            found =0 ;
            for(k=0;k<f;k++)
            {
                if(frames[k]==seq[i])
                {
                    found=1;
                    secChance[k]=1;
                }
            }
            if(found==0)
            {
                if(secChance[j]==1)
                {
                    secChance[j]=0;
                    j=(j+1)%f;
                }
                frames[j]=seq[i];
                j = (j+1)%f;
                miss++;
                for(k=0;k<f;k++)
                {
                    cout<<frames[k]<<"\t";
                }

            }
            cout<<"\n";

        }
        cout<<"\n"<<"Total miss = "<<miss<<"\n";

    }



    return 0;

}
