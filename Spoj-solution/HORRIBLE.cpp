    #include<bits/stdc++.h>
 
 using namespace std;
 
 typedef long long int ll;
 long long tree[450000];
 long long lazy[450000];
 
 void updateRangeUtil(ll si, ll ss, ll se, ll us,
                    ll ue, ll diff)
{
    // If lazy value is non-zero for current node of segment
    // tree, then there are some pending updates. So we need
    // to make sure that the pending updates are done before
    // making new updates. Because this value may be used by
    // parent after recursive calls (See last line of this
    // function)
    if (lazy[si] != 0)
    {
        // Make pending updates using value stored in lazy
        // nodes
        tree[si] += (se-ss+1)*lazy[si];
 
        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // We can postpone updating children we don't
            // need their new values now.
            // Since we are not yet updating children of si,
            // we need to set lazy flags for the children
            lazy[si*2 + 1]   += lazy[si];
            lazy[si*2 + 2]   += lazy[si];
        }
 
        // Set the lazy value for current node as 0 as it
        // has been updated
        lazy[si] = 0;
    }
 
    // out of range
    if (ss>se || ss>ue || se<us)
        return ;
 
    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        tree[si] += (se-ss+1)*diff;
 
        // same logic for checking leaf node or not
        if (ss != se)
        {
            // This is where we store values in lazy nodes,
            // rather than updating the segment tree itelf
            // Since we don't need these updated values now
            // we postpone updates by storing values in lazy[]
            lazy[si*2 + 1]   += diff;
            lazy[si*2 + 2]   += diff;
        }
        return;
    }
 
    // If not completely in rang, but overlaps, recur for
    // children,
   ll mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);
 
    // And use the result of children calls to update this
    // node
    tree[si] = tree[si*2+1] + tree[si*2+2];
}
 
// Function to update a range of values in segment
// tree
/*  us and eu -> starting and ending indexes of update query
    ue  -> ending index of update query
    diff -> which we need to add in the range us to ue */
void updateRange(ll n, ll us, ll ue, ll diff)
{
   updateRangeUtil(0, 0, n-1, us, ue, diff);
}
 
 
/*  A recursive function to get the sum of values in given
    range of the array. The following are parameters for
    this function.
    si --> Index of current node in the segment tree.
           Initially 0 is passed as root is always at'
           index 0
    ss & se  --> Starting and ending indexes of the
                 segment represented by current node,
                 i.e., tree[si]
    qs & qe  --> Starting and ending indexes of query
                 range */
ll getSumUtil(ll ss, ll se, ll qs, ll qe, ll si)
{
    // If lazy flag is set for current node of segment tree,
    // then there are some pending updates. So we need to
    // make sure that the pending updates are done before
    // processing the sub sum query
    if (lazy[si] != 0)
    {
        // Make pending updates to this node. Note that this
        // node represents sum of elements in arr[ss..se] and
        // all these elements must be increased by lazy[si]
        tree[si] += (se-ss+1)*lazy[si];
 
        // checking if it is not leaf node because if
        // it is leaf node then we cannot go further
        if (ss != se)
        {
            // Since we are not yet updating children os si,
            // we need to set lazy values for the children
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
 
        // unset the lazy value for current node as it has
        // been updated
        lazy[si] = 0;
    }
 
    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0;
 
    // At this point we are sure that pending lazy updates
    // are done for current node. So we can return value 
    // (same as it was for query in our previous post)
 
    // If this segment lies in range
    if (ss>=qs && se<=qe)
        return tree[si];
 
    // If a part of this segment overlaps with the given
    // range
    ll mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}
 
// Return sum of elements in range from index qs (quey
// start) to qe (query end).  It mainly uses getSumUtil()
ll getSum(ll n, ll qs, ll qe)
{
    // Check for erroneous input values
     
 
    return getSumUtil(0, n-1, qs, qe, 0);
}
 
  


int main()
{
        long int t;
        cin>>t;
        //buildTree(1,200005,1);
       
        
        
 
        
       while(t--)
        {
            long long int n,c;
            cin>>n>>c;
            memset(tree,0,sizeof(tree));
            memset(lazy,0,sizeof(lazy));
            while(c--)
            {
            long long int p,q,v,choice;
            cin>>choice;
            
            if(choice==0)
            {
                cin>>p>>q>>v;
                updateRange(n,p-1,q-1,v);
                 
                
            }
            
            if(choice==1)
            {
                cin>>p>>q;
                long long int sum=getSum(n,p-1,q-1);
                
                 
                cout<<sum<<endl;
            
            }
            
        	}
}

}