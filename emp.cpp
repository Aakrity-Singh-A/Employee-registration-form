void hig_tax();
{
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(s[i].tax<s[j].tax)
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
	cout<<"The sorted details are"
		for(i=0;i<n;i++)
		{
			cout<<"Name"<<s[i].name<<endl;
			cout<<"Id"<<s[i].id<<endl;
			cout<<"NET Salary"<<s[i].net<<endl;
		}
}