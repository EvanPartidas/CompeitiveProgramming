import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;

public class AddingWords {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		main:
		while(true){
			HashMap<String,Integer> def =new HashMap<>();
			HashMap<Integer,String> res =new HashMap<>();
			String line;
			label:
			while((line=br.readLine())!=null){
				String[] command = line.split(" ");
				switch(command[0]){
				case "def":{
					if(def.containsKey(command[1])){
						res.remove(def.get(command[1]));
					}
					def.put(command[1], Integer.parseInt(command[2]));
					res.put(Integer.parseInt(command[2]),command[1]);
					break;
				}
				case "calc":{
					if(!def.containsKey(command[1])){
						for(int j=1;j<command.length;j++){
							bw.write(command[j]+" ");
						}
						bw.write("unknown");
						bw.newLine();
						bw.flush();
						continue label;
					}
					int sum=def.get(command[1]);
					for(int i=2;i<command.length;i+=2){
						if(command[i].equals("+")){
							if(!def.containsKey(command[i+1])){
								for(int j=1;j<command.length;j++){
									bw.write(command[j]+" ");
								}
								bw.write("unknown");
								bw.newLine();
								bw.flush();
								continue label;
							}
							sum+=def.get(command[i+1]);
						}
						else if(command[i].equals("-")){
							if(!def.containsKey(command[i+1])){
								for(int j=1;j<command.length;j++){
									bw.write(command[j]+" ");
								}
								bw.write("unknown");
								bw.newLine();
								bw.flush();
								continue label;
							}
							sum-=def.get(command[i+1]);
						}
					}
					if(!res.containsKey(sum)){
						for(int j=1;j<command.length;j++){
							bw.write(command[j]+" ");
						}
						bw.write("unknown");
						bw.newLine();
						bw.flush();
						continue label;
					}
					for(int j=1;j<command.length;j++){
						bw.write(command[j]+" ");
					}
					bw.write(res.get(sum));
					bw.newLine();
					bw.flush();
					continue label;
				}
				case "clear":{
					continue main;
				}
				}
			}
			break;
		}
	}

}
