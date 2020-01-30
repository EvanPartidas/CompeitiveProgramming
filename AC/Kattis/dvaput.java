import java.io.BufferedReader;
import java.io.InputStreamReader;

public class dvaput {
	static class SuffixArray{
		char STR[];
		int split,SA[],RA[],TMP[],N,lcpIndIn2,lcpIndIn1,length;
		SuffixArray(String str1){
			STR = new char[str1.length()+1];
			int ind=0;
			for(int i=0;i<str1.length();i++) 
				STR[ind++]=str1.charAt(i);
			split = ind;
			STR[ind++] = '$';
			SA = new int[STR.length];
			TMP = new int[STR.length];
			RA = new int[STR.length];
			N = STR.length;
			construct();
		}

		void countsort(int k,int size) {
			int i;
			int count[] = new int[size];
			for(i=0;i<size;i++)
				count[i]=0;
			for(i=0;i<N;i++)
				count[i+k<N?RA[i+k]:0]++;    
			for(i=1;i<size;i++)
				count[i]+=count[i-1];
			for(i=N-1;i>=0;i--)
				TMP[--count[SA[i]+k<N?RA[SA[i]+k]:0]] = SA[i];
			for(i=0;i<N;i++)
				SA[i]=TMP[i];			
		}

		void construct() {
			int i,k=1,r;
			for(i=0;i<N;i++) {
				SA[i]=i;
				RA[i]=STR[i];
			}
			for(k=1;k<N;k<<=1) {
				countsort(k,Math.max(N+1,300));
				countsort(0,Math.max(N+1,300));
				TMP[SA[0]]=r=0;
				for(i=1;i<N;i++){
					TMP[SA[i]]=
							(RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;
				}
				for (i = 0; i < N; i++)
					RA[i] = TMP[i];
				if (RA[SA[N-1]] == N-1) break;
			}
		}		
		int lcp(){
			int len=0;
			int prefix=0;
			int i;
			for(i=1;i<N;i++)
				TMP[SA[i]]=SA[i-1];
			for(i = 0;i<N-1;i++){
				while(STR[i+len]==STR[TMP[i]+len]) len++;
				if(len>prefix) {
					prefix = len;		
				}
				len = Math.max(len-1,0);
			}
			length = prefix;
			return prefix;
		}
	}
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		SuffixArray sa = new SuffixArray(br.readLine());
		System.out.println(sa.lcp());

	}

}
