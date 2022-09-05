void tarjan(int x,int father){
	dfn[x]=low[x]=++nowtime;
	s.push(x);
	for(register int i=head[x];i;i=e[i].next){
		int v(e[i].to);
		if(!dfn[v]){
			tarjan(v,i);
			low[x]=Min(low[x],low[v]);
		}else if(i!=(father^1))low[x]=Min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		++dcccnt;
		int k;
		do{
			k=s.pop();
			belong[k]=dcccnt;
		}while(k!=x);
	}
}
int main(){
	for(register int i=1;i<=n;++i)
		if(!dfn[i])tarjan(i,i);
}