#include<bits/stdc++.h>
using namespace std;
struct condition{
    int num_tab_col = 0 ;
    int num_col_nm = 0 ;
    int order  = 0 ;
    int cnt   =  0 ;  //  1 for or  2 for and
    string cmd ;
    string tab_col_0 ;
    string tab_col_1 ;
    string tab_col_2 ;
    string tab_col_3 ;
    string tab_col_4 ;
    string tab_col_5 ;
    string tab_col_6 ;

    string col_nm;  // 欄位
    string optr;    // 運算子
    int  value;    // 值
    string lk_value ;

    string col_nm_1;
    string optr_1 ;
    int  value_1 ;
    string lk_value_1;

    string col_nm_2;
    string optr_2 ;
    int  value_2 ;
    string lk_value_2 ;

    string col_nm_3;
    string optr_3 ;
    int  value_3 ;
    string lk_value_3 ;

    string order_by_1 ;
    string order_by_2 ;

};

struct student {
    int  ID ;
    string Name ;
    int   StudentID;
    string Class;
    string Email ;
    int   Phone;
    int isValid = 0  ;
};

long long int ston(  string s  )
{
    int s_len = s.length( ) ;
    long long int ans = 0 ;
    for( int i = s_len-1 , j = 0  ; i>= 0 ;  i-- , j++ )
    {
        ans = ( long long int ) (  ans + ( s[ j ] - '0' )*pow( 10.0 , i )  )  ;
    }
    return ans ;
}

struct condition conditions[ 20 ] ;

bool DESC_ID(struct student A , struct student B)
{
        return A.ID > B.ID;
}

bool ASC_ID(struct student A , struct student B)
{
        return A.ID < B.ID ;
}

bool DESC_StudentID(struct student A , struct student B)
{
        return A.StudentID > B.StudentID ;
}

bool ASC_StudentID(struct student A , struct student B)
{
        return A.StudentID < B.StudentID;
}

bool DESC_Phone(struct student A , struct student B)
{
        return A.Phone > B.Phone;
}

bool ASC_Phone(struct student A , struct student B)
{
        return A.Phone < B.Phone;
}

void CopySort(  struct student table[ ] , struct condition conditions[ ] , int i ,  int j )
{
    if( conditions[ i ].order_by_1 == "ID" )
    {
        if( conditions[ i ].order_by_2 == "DESC" )
        {
            sort( table , table + j , DESC_ID ) ;
        }
        else if( conditions[ i ].order_by_2 == "ASC" )
        {
            sort( table , table + j , ASC_ID ) ;
        }
    }
    else if( conditions[ i ].order_by_1 == "StudentID" )
    {
        if( conditions[ i ].order_by_2 == "DESC" )
        {
            sort( table , table + j , DESC_StudentID ) ;
        }
        else if( conditions[ i ].order_by_2 == "ASC" )
        {
            sort( table , table + j , ASC_StudentID ) ;
        }
    }
    else if( conditions[ i ].order_by_1 == "Phone" )
    {
        if( conditions[ i ].order_by_2 == "DESC" )
        {
            sort( table , table + j , DESC_Phone ) ;
        }
        else if( conditions[ i ].order_by_2 == "ASC" )
        {
            sort( table , table + j , ASC_Phone ) ;
        }
    }
}


int read_percent( struct condition conditions[ ]  , int i , int now )
{
    int found = 0  ;// 1 first // 2 vack // 3 both
    if( now == 1 )
    {
        int len = conditions[ i ].lk_value.length( ) ;
        int times = 0 ;
        for( int j = 0 ; j < len ; j++ )
        {
            if( conditions[ i ].lk_value[ j ] == 37 &&  j == 0 )
            {
                times++ ;
                found = 1 ;
            }
            if( conditions[ i ].lk_value[ j ] ==  37  &&  j  == len - 1 )
            {
                times++ ;
                found = 2 ;
            }
        }
        if( times == 2 )
        {
            found = 3 ;
        }
    }
    else if(  now == 2  )
    {
        int len = conditions[ i ].lk_value_1.length( ) ;
        int times = 0 ;
        for( int j = 0 ; j < len ; j++ )
        {
            if( conditions[ i ].lk_value_1[ j ] == 37 &&  j == 0 )
            {
                times++ ;
                found = 1 ;
            }
            if( conditions[ i ].lk_value_1[ j ] ==  37  &&  j  == len - 1 )
            {
                times++ ;
                found = 2 ;
            }
        }
        if( times == 2 )
        {
            found = 3 ;
        }
    }
    else if( now == 3 )
    {
        int len = conditions[ i ].lk_value_2.length( ) ;
        int times = 0 ;
        for( int j = 0 ; j < len ; j++ )
        {
            if( conditions[ i ].lk_value_2[ j ] == 37 &&  j == 0 )
            {
                times++ ;
                found = 1 ;
            }
            if( conditions[ i ].lk_value_2[ j ] ==  37  &&  j  == len - 1 )
            {
                times++ ;
                found = 2 ;
            }
        }
        if( times == 2 )
        {
            found = 3 ;
        }
    }
    else if( now == 4 )
    {
        int len = conditions[ i ].lk_value_3.length( ) ;
        int times = 0 ;
        for( int j = 0 ; j < len ; j++ )
        {
            if( conditions[ i ].lk_value_3[ j ] == 37 &&  j == 0 )
            {
                times++ ;
                found = 1 ;
            }
            if( conditions[ i ].lk_value_3[ j ] ==  37  &&  j  == len - 1 )
            {
                times++ ;
                found = 2 ;
            }
        }
        if( times == 2 )
        {
            found = 3 ;
        }
    }
    return found ;
}

void read_like_cmd( struct condition conditions[ ] , int  found  , int i  , int now  )
{
    if(  now == 1 )
    {
        if( found == 0 )
        {
            return;
        }
        else if( found == 1 )
        {
            int len =  conditions[ i ].lk_value.length( ) ;
            string tmp = conditions[ i ].lk_value.substr( 1 , len - 1  ) ;
            conditions[ i ].lk_value = tmp ;
        }
        else if( found == 2 )
        {
            int len =  conditions[ i ].lk_value.length( ) ;
            string tmp = conditions[ i ].lk_value.substr( 0 , len - 1  ) ;
            conditions[ i ].lk_value = tmp ;
        }
        else if( found == 3 )
        {
            int len =  conditions[ i ].lk_value.length( ) ;
            string tmp = conditions[ i ].lk_value.substr( 1 , len - 2  ) ;
            conditions[ i ].lk_value = tmp ;
        }
    }
    else if( now == 2 )
    {
        if( found == 0 )
        {
            return;
        }
        else if( found == 1 )
        {
            int len =  conditions[ i ].lk_value_1.length( ) ;
            string tmp = conditions[ i ].lk_value_1.substr( 1 , len - 1  ) ;
            conditions[ i ].lk_value_1 = tmp ;
        }
        else if( found == 2 )
        {
            int len =  conditions[ i ].lk_value_1.length( ) ;
            string tmp = conditions[ i ].lk_value_1.substr( 0 , len - 1  ) ;
            conditions[ i ].lk_value_1 = tmp ;
        }
        else if( found == 3 )
        {
            int len =  conditions[ i ].lk_value_1.length( ) ;
            string tmp = conditions[ i ].lk_value_1.substr( 1 , len - 2  ) ;
            conditions[ i ].lk_value_1 = tmp ;
        }
    }
    else if(  now == 3  )
    {
        if( found == 0 )
        {
            return;
        }
        else if( found == 1 )
        {
            int len =  conditions[ i ].lk_value_2.length( ) ;
            string tmp = conditions[ i ].lk_value_2.substr( 1 , len - 1  ) ;
            conditions[ i ].lk_value_2 = tmp ;
        }
        else if( found == 2 )
        {
            int len =  conditions[ i ].lk_value_2.length( ) ;
            string tmp = conditions[ i ].lk_value_2.substr( 0 , len - 1  ) ;
            conditions[ i ].lk_value_2 = tmp ;
        }
        else if( found == 3 )
        {
            int len =  conditions[ i ].lk_value_2.length( ) ;
            string tmp = conditions[ i ].lk_value_2.substr( 1 , len - 2  ) ;
            conditions[ i ].lk_value_2 = tmp ;
        }
    }
    else if( now == 4 )
    {
        if( found == 0 )
        {
            return;
        }
        else if( found == 1 )
        {
            int len =  conditions[ i ].lk_value_3.length( ) ;
            string tmp = conditions[ i ].lk_value_3.substr( 1 , len - 1  ) ;
            conditions[ i ].lk_value_3 = tmp ;
        }
        else if( found == 2 )
        {
            int len =  conditions[ i ].lk_value_3.length( ) ;
            string tmp = conditions[ i ].lk_value_3.substr( 0 , len - 1  ) ;
            conditions[ i ].lk_value_3 = tmp ;
        }
        else if( found == 3 )
        {
            int len =  conditions[ i ].lk_value_3.length( ) ;
            string tmp = conditions[ i ].lk_value_3.substr( 1 , len - 2  ) ;
            conditions[ i ].lk_value_3 = tmp ;
        }
    }
    return ;
}

void dele_cmd(struct student table[ ]  , struct condition conditions[ ] , int i , int j )
{
     if(  conditions[ i ].col_nm != "ID" && conditions[ i ].col_nm != "StudentID" && conditions[ i ].col_nm !="Phone" )
     {
        if( conditions[ i ].col_nm != "Name" && conditions[ i ].col_nm != "Class" && conditions[ i ].col_nm !="Email" )
        {
            table[ j ].isValid = 2 ;
            return ;
        }
     } // DELETE ALL ;
    for( int k = 0 ; k < conditions[ i ].num_col_nm ; k++ )
    {
        if( conditions[ i ].cnt == 2 ) // and
        {
            if( k == 0 )
            {
                if(  conditions[ i ].col_nm == "ID" )
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value )
                        {
                             table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                }
                else if( conditions[ i ].col_nm == "StudentID")
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                        if(  table[ j ].StudentID  >  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].StudentID  <  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                         if(  table[ j ].StudentID  >=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                         if(  table[ j ].StudentID  <=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                }
                else if(  conditions[ i ].col_nm == "Phone"  )
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                         if(  table[ j ].Phone  >  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                        if(  table[ j ].Phone  <=  conditions[ i ].value )
                        {
                             table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                }
                else if(  conditions[ i ].col_nm == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value , 0 ) ; // table後面    codition

                    if( a == string::npos )  break;  //  not  like  // k = 1... 和 or 的logic
                    else   table[ j ].isValid = 2 ;
                }
                else if( conditions[ i ].col_nm == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value , 0 ) ;

                    if( a == string::npos )  break;  //  not  like
                    else   table[ j ].isValid = 2 ; // like 要刪掉惹
                }
                else if( conditions[ i ].col_nm == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value , 0 ) ;

                    if( a == string::npos )  break;  //  not  like
                    else   table[ j ].isValid = 2 ;
                }
            }
            if( k == 1 )
            {
                if(  conditions[ i ].col_nm_1 == "ID" )
                {
                    if(  conditions[ i ].optr_1 == ">"  )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "<" )
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "!=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == ">=")
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "<=" )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                }
                else if( conditions[ i ].col_nm_1 == "StudentID")
                {
                    if(  conditions[ i ].optr_1 == ">"  )
                    {
                        if(  table[ j ].StudentID  <=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "<" )
                    {
                        if(  table[ j ].StudentID  >=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "!=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == ">=")
                    {
                         if(  table[ j ].StudentID  <  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "<=" )
                    {
                         if(  table[ j ].StudentID  >  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_1 == "Phone"  )
                {
                    if(  conditions[ i ].optr_1 == ">"  )
                    {
                         if(  table[ j ].Phone  <=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "<" )
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "!=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == ">=")
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "<=" )
                    {
                        if(  table[ j ].Phone  >  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_1 == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  2 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 2  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value_1 , 0 ) ; // table後面    codition

                    if( a == string::npos )
                    {
                        table[ j ].isValid = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_1 == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  2 ) ;
                    read_like_cmd( conditions , found ,  i , 2  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value_1 , 0 ) ;

                    if( a == string::npos )
                    {
                        table[ j ].isValid = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_1 == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  2 ) ;
                    read_like_cmd( conditions , found ,  i , 2  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value_1 , 0 ) ;

                    if( a == string::npos )
                    {
                        table[ j ].isValid = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
            }
            if( k == 2 )
            {
                if(  conditions[ i ].col_nm_2 == "ID" )
                {
                    if(  conditions[ i ].optr_2 == ">"  )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "<" )
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "!=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == ">=")
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "<=" )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                }
                else if( conditions[ i ].col_nm_2 == "StudentID")
                {
                    if(  conditions[ i ].optr_2 == ">"  )
                    {
                        if(  table[ j ].StudentID  <=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "<" )
                    {
                        if(  table[ j ].StudentID  >=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "!=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == ">=")
                    {
                         if(  table[ j ].StudentID  <  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "<=" )
                    {
                         if(  table[ j ].StudentID  >  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_2 == "Phone"  )
                {
                    if(  conditions[ i ].optr_2 == ">"  )
                    {
                         if(  table[ j ].Phone  <=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "<" )
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "!=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == ">=")
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "<=" )
                    {
                        if(  table[ j ].Phone  >  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_2 == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  3 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 3  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value_2 , 0 ) ; // table後面    codition

                    if( a == string::npos )
                    {
                        table[ j ].isValid = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_2 == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  3 ) ;
                    read_like_cmd( conditions , found ,  i , 3  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value_2 , 0 ) ;

                    if( a == string::npos )
                    {
                        table[ j ].isValid = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_2 == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  3 ) ;
                    read_like_cmd( conditions , found ,  i , 3  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value_2 , 0 ) ;

                    if( a == string::npos )
                    {
                        table[ j ].isValid = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
            }
            if( k == 3 )
            {
                if(  conditions[ i ].col_nm_3 == "ID" )
                {
                    if(  conditions[ i ].optr_3 == ">"  )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "<" )
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "!=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == ">=")
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "<=" )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                }
                else if( conditions[ i ].col_nm_3 == "StudentID")
                {
                    if(  conditions[ i ].optr_3 == ">"  )
                    {
                        if(  table[ j ].StudentID  <=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "<" )
                    {
                        if(  table[ j ].StudentID  >=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "!=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == ">=")
                    {
                         if(  table[ j ].StudentID  <  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "<=" )
                    {
                         if(  table[ j ].StudentID  >  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_3 == "Phone"  )
                {
                    if(  conditions[ i ].optr_3 == ">"  )
                    {
                         if(  table[ j ].Phone  <=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "<" )
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "!=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == ">=")
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "<=" )
                    {
                        if(  table[ j ].Phone  >  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 0 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_3 == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  4 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 4 ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value_3 , 0 ) ; // table後面    codition

                    if( a == string::npos )
                    {
                        table[ j ].isValid = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_3 == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  4 ) ;
                    read_like_cmd( conditions , found ,  i , 4  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value_3 , 0 ) ;

                    if( a == string::npos )
                    {
                        table[ j ].isValid = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_3 == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  4 ) ;
                    read_like_cmd( conditions , found ,  i , 4  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value_3 , 0 ) ;

                    if( a == string::npos )
                    {
                        table[ j ].isValid = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
            }
        } // and condition
        else if(  conditions[ i ].cnt == 1 ) // OR  //
        {
            if( k == 0 )
            {
                if(  conditions[ i ].col_nm == "ID" )
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value )
                        {
                             table[ j ].isValid = 2 ;
                             break;
                        }
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break;
                        }
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break;
                        }
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break;
                        }
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break;
                        }
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break;
                        }
                    }
                }
                else if( conditions[ i ].col_nm == "StudentID")
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                        if(  table[ j ].StudentID  >  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break;
                        }
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].StudentID  <  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].StudentID  !=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                         if(  table[ j ].StudentID  >=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                         if(  table[ j ].StudentID  <=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm == "Phone"  )
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                         if(  table[ j ].Phone  >  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break;
                        }
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                            break;
                        }
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                        if(  table[ j ].Phone  <=  conditions[ i ].value )
                        {
                             table[ j ].isValid = 2 ;
                             break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value , 0 ) ; // table後面    codition

                    if( a != string::npos )  // like  >>  要刪掉 >> break
                    {
                        table[ j ].isValid = 2 ;
                        break;  //  not  like  // k = 1... 和 or 的logic
                    }

                }
                else if( conditions[ i ].col_nm == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value , 0 ) ;

                    if( a != string::npos )  // like  >>  要刪掉 >> break
                    {
                        table[ j ].isValid = 2 ;
                        break;  //  not  like  // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value , 0 ) ;

                   if( a != string::npos )  // like  >>  要刪掉 >> break
                    {
                        table[ j ].isValid = 2 ;
                        break;  //  not  like  // k = 1... 和 or 的logic
                    }

                }
            }
            if( k == 1 )
            {
                if(  conditions[ i ].col_nm_1 == "ID" )
                {
                    if(  conditions[ i ].optr_1 == ">"  )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "<" )
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "!=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == ">=")
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "<=" )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                }
                else if( conditions[ i ].col_nm_1 == "StudentID")
                {
                    if(  conditions[ i ].optr_1 == ">"  )
                    {
                        if(  table[ j ].StudentID  >  conditions[ i ].value_1 )
                        {
                           table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "<" )
                    {
                        if(  table[ j ].StudentID  <  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "!=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == ">=")
                    {
                         if(  table[ j ].StudentID  >=  conditions[ i ].value_1 )
                        {
                           table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "<=" )
                    {
                         if(  table[ j ].StudentID  <=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_1 == "Phone"  )
                {
                    if(  conditions[ i ].optr_1 == ">"  )
                    {
                         if(  table[ j ].Phone  >  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "<" )
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value_1 )
                        {
                           table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "!=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == ">=")
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value_1 )
                        {
                           table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "<=" )
                    {
                        if(  table[ j ].Phone  <=  conditions[ i ].value_1 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_1 == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  2 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 2  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value_1 , 0 ) ; // table後面    codition

                    if( a != string::npos ) //代表like >> 要刪掉
                    {
                        table[ j ].isValid = 2 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_1 == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  2 ) ;
                    read_like_cmd( conditions , found ,  i , 2  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value_1 , 0 ) ;

                    if( a != string::npos ) //代表like >> 要刪掉
                    {
                        table[ j ].isValid = 2 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_1 == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  2 ) ;
                    read_like_cmd( conditions , found ,  i , 2  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value_1 , 0 ) ;

                   if( a != string::npos ) //代表like >> 要刪掉
                    {
                        table[ j ].isValid = 2 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
            }  //xddd
            if( k == 2 )
            {
                if(  conditions[ i ].col_nm_2 == "ID" )
                {
                    if(  conditions[ i ].optr_2 == ">"  )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "<" )
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "!=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == ">=")
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "<=" )
                    {
                        if(  table[ j ].ID  <= conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                }
                else if( conditions[ i ].col_nm_2 == "StudentID")
                {
                    if(  conditions[ i ].optr_2 == ">"  )
                    {
                        if(  table[ j ].StudentID  >  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "<" )
                    {
                        if(  table[ j ].StudentID  <  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "!=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == ">=")
                    {
                         if(  table[ j ].StudentID  >=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "<=" )
                    {
                         if(  table[ j ].StudentID  <=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_2 == "Phone"  )
                {
                    if(  conditions[ i ].optr_2 == ">"  )
                    {
                         if(  table[ j ].Phone  >  conditions[ i ].value_2 )
                        {
                           table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "<" )
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "!=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == ">=")
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "<=" )
                    {
                        if(  table[ j ].Phone  <=  conditions[ i ].value_2 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_2 == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  3 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 3  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value_2 , 0 ) ; // table後面    codition

                    if( a != string::npos ) //代表like 藥膳調喔
                    {
                        table[ j ].isValid = 2 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_2 == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  3 ) ;
                    read_like_cmd( conditions , found ,  i , 3  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value_2 , 0 ) ;

                    if( a != string::npos ) //代表like 藥膳調喔
                    {
                        table[ j ].isValid = 2 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_2 == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  3 ) ;
                    read_like_cmd( conditions , found ,  i , 3  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value_2 , 0 ) ;

                    if( a != string::npos ) //代表like 藥膳調喔
                    {
                        table[ j ].isValid = 2 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
            }
            if( k == 3 )
            {
                if(  conditions[ i ].col_nm_3 == "ID" )
                {
                    if(  conditions[ i ].optr_3 == ">"  )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "<" )
                    {
                        if(  table[ j ].ID  < conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value_3 )
                        {
                             table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "!=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == ">=")
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "<=" )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value_3 )
                        {
                             table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                }
                else if( conditions[ i ].col_nm_3 == "StudentID")
                {
                    if(  conditions[ i ].optr_3 == ">"  )
                    {
                        if(  table[ j ].StudentID  >  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "<" )
                    {
                        if(  table[ j ].StudentID  <  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "!=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == ">=")
                    {
                         if(  table[ j ].StudentID  >=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "<=" )
                    {
                         if(  table[ j ].StudentID  <=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_3 == "Phone"  )
                {
                    if(  conditions[ i ].optr_3 == ">"  )
                    {
                         if(  table[ j ].Phone  >  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "<" )
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "!=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == ">=")
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "<=" )
                    {
                        if(  table[ j ].Phone  <=  conditions[ i ].value_3 )
                        {
                            table[ j ].isValid = 2 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_3 == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  4 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 4 ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value_3 , 0 ) ; // table後面    codition

                    if( a != string::npos ) // 代表Like
                    {
                        table[ j ].isValid = 2  ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_3 == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  4 ) ;
                    read_like_cmd( conditions , found ,  i , 4  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value_3 , 0 ) ;

                    if( a != string::npos ) // 代表Like
                    {
                        table[ j ].isValid = 2  ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_3 == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  4 ) ;
                    read_like_cmd( conditions , found ,  i , 4  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value_3 , 0 ) ;

                    if( a != string::npos ) // 代表Like
                    {
                        table[ j ].isValid = 2  ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
            }
        }
        else if( conditions[ i ].cnt == 0 ) // ONLY COL = 1 ; // only satisfy one solution
        {
                if(  conditions[ i ].col_nm == "ID" )
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value )
                        {
                             table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                }
                else if( conditions[ i ].col_nm == "StudentID")
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                        if(  table[ j ].StudentID  >  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].StudentID  <  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                         if(  table[ j ].StudentID  >=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                         if(  table[ j ].StudentID  <=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                }
                else if(  conditions[ i ].col_nm == "Phone"  )
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                         if(  table[ j ].Phone  >  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value )
                        {
                            table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                        if(  table[ j ].Phone  <=  conditions[ i ].value )
                        {
                             table[ j ].isValid = 2 ;
                        }
                        else
                        break ;
                    }
                }
                else if(  conditions[ i ].col_nm == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value , 0 ) ; // table後面    codition

                    if( a == string::npos )  break;  //  not  like  // k = 1... 和 or 的logic
                    else   table[ j ].isValid = 2 ;
                }
                else if( conditions[ i ].col_nm == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value , 0 ) ;

                    if( a == string::npos )  break;  //  not  like
                    else   table[ j ].isValid = 2 ; // like 要刪掉惹
                }
                else if( conditions[ i ].col_nm == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value , 0 ) ;

                    if( a == string::npos )  break;  //  not  like
                    else   table[ j ].isValid = 2 ;
                }
        }
    }
    return ;
}

int isStudentValid( struct student table[ ]  , struct condition conditions[ ] , int i , int j )
{
    int dete = 0 ; // 1  choose it
    if(  conditions[ i ].col_nm != "ID" && conditions[ i ].col_nm != "StudentID" && conditions[ i ].col_nm !="Phone" )
     {
        if( conditions[ i ].col_nm != "Name" && conditions[ i ].col_nm != "Class" && conditions[ i ].col_nm !="Email" )
        {
            dete =  1  ;
            return dete ;
        }
    } //  select all ;
    for( int k = 0 ; k < conditions[ i ].num_col_nm ; k++ )
    {
        if( conditions[ i ].cnt == 2 ) // and
        {
            if( k == 0 )
            {
                if(  conditions[ i ].col_nm == "ID" )
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value )
                        {
                             dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value )
                        {
                           dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                }
                else if( conditions[ i ].col_nm == "StudentID")
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                        if(  table[ j ].StudentID  >  conditions[ i ].value )
                        {
                           dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].StudentID  <  conditions[ i ].value )
                        {
                           dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                         if(  table[ j ].StudentID  >=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                         if(  table[ j ].StudentID  <=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                }
                else if(  conditions[ i ].col_nm == "Phone"  )
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                         if(  table[ j ].Phone  >  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                        if(  table[ j ].Phone  <=  conditions[ i ].value )
                        {
                             dete = 1 ;
                        }
                        else
                        break ;
                    }
                }
                else if(  conditions[ i ].col_nm == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value , 0 ) ; // table後面    codition

                    if( a == string::npos )  break;  //  not  like  // k = 1... 和 or 的logic
                    else   dete = 1;
                }
                else if( conditions[ i ].col_nm == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value , 0 ) ;

                    if( a == string::npos )  break;  //  not  like
                    else   dete = 1; // like 要刪掉惹
                }
                else if( conditions[ i ].col_nm == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value , 0 ) ;

                    if( a == string::npos )  break;  //  not  like
                    else   dete = 1;
                }
            }
            if( k == 1 )
            {
                if(  conditions[ i ].col_nm_1 == "ID" )
                {
                    if(  conditions[ i ].optr_1 == ">"  )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "<" )
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "!=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == ">=")
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "<=" )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                }
                else if( conditions[ i ].col_nm_1 == "StudentID")
                {
                    if(  conditions[ i ].optr_1 == ">"  )
                    {
                        if(  table[ j ].StudentID  <=  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "<" )
                    {
                        if(  table[ j ].StudentID  >=  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "!=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == ">=")
                    {
                         if(  table[ j ].StudentID  <  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "<=" )
                    {
                         if(  table[ j ].StudentID  >  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_1 == "Phone"  )
                {
                    if(  conditions[ i ].optr_1 == ">"  )
                    {
                         if(  table[ j ].Phone  <=  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "<" )
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "!=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == ">=")
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "<=" )
                    {
                        if(  table[ j ].Phone  >  conditions[ i ].value_1 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_1 == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  2 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 2  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value_1 , 0 ) ; // table後面    codition

                    if( a == string::npos )
                    {
                        dete = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_1 == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  2 ) ;
                    read_like_cmd( conditions , found ,  i , 2  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value_1 , 0 ) ;

                    if( a == string::npos )
                    {
                        dete = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_1 == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  2 ) ;
                    read_like_cmd( conditions , found ,  i , 2  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value_1 , 0 ) ;

                    if( a == string::npos )
                    {
                        dete = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
            }
            if( k == 2 )
            {
                if(  conditions[ i ].col_nm_2 == "ID" )
                {
                    if(  conditions[ i ].optr_2 == ">"  )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "<" )
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "!=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == ">=")
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "<=" )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                }
                else if( conditions[ i ].col_nm_2 == "StudentID")
                {
                    if(  conditions[ i ].optr_2 == ">"  )
                    {
                        if(  table[ j ].StudentID  <=  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "<" )
                    {
                        if(  table[ j ].StudentID  >=  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "!=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == ">=")
                    {
                         if(  table[ j ].StudentID  <  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "<=" )
                    {
                         if(  table[ j ].StudentID  >  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_2 == "Phone"  )
                {
                    if(  conditions[ i ].optr_2 == ">"  )
                    {
                         if(  table[ j ].Phone  <=  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "<" )
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "!=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == ">=")
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "<=" )
                    {
                        if(  table[ j ].Phone  >  conditions[ i ].value_2 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_2 == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  3 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 3  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value_2 , 0 ) ; // table後面    codition

                    if( a == string::npos )
                    {
                        dete = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_2 == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  3 ) ;
                    read_like_cmd( conditions , found ,  i , 3  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value_2 , 0 ) ;

                    if( a == string::npos )
                    {
                        dete = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_2 == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  3 ) ;
                    read_like_cmd( conditions , found ,  i , 3  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value_2 , 0 ) ;

                    if( a == string::npos )
                    {
                        dete = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
            }
            if( k == 3 )
            {
                if(  conditions[ i ].col_nm_3 == "ID" )
                {
                    if(  conditions[ i ].optr_3 == ">"  )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "<" )
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "!=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == ">=")
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "<=" )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                }
                else if( conditions[ i ].col_nm_3 == "StudentID")
                {
                    if(  conditions[ i ].optr_3 == ">"  )
                    {
                        if(  table[ j ].StudentID  <=  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "<" )
                    {
                        if(  table[ j ].StudentID  >=  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "!=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == ">=")
                    {
                         if(  table[ j ].StudentID  <  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "<=" )
                    {
                         if(  table[ j ].StudentID  >  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_3 == "Phone"  )
                {
                    if(  conditions[ i ].optr_3 == ">"  )
                    {
                         if(  table[ j ].Phone  <=  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "<" )
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "!=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == ">=")
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "<=" )
                    {
                        if(  table[ j ].Phone  >  conditions[ i ].value_3 )
                        {
                            dete = 0 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_3 == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  4 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 4 ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value_3 , 0 ) ; // table後面    codition

                    if( a == string::npos )
                    {
                        dete = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_3 == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  4 ) ;
                    read_like_cmd( conditions , found ,  i , 4  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value_3 , 0 ) ;

                    if( a == string::npos )
                    {
                        dete = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_3 == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  4 ) ;
                    read_like_cmd( conditions , found ,  i , 4  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value_3 , 0 ) ;

                    if( a == string::npos )
                    {
                        dete = 0 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
            }
        } // and condition
        else if(  conditions[ i ].cnt == 1 ) // OR  // 達成一項即可刪掉惹喔  然後就 跳粗乃
        {
            if( k == 0 )
            {
                if(  conditions[ i ].col_nm == "ID" )
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value )
                        {
                             dete = 1 ;
                             break;
                        }
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break;
                        }
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break;
                        }
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break;
                        }
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break;
                        }
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break;
                        }
                    }
                }
                else if( conditions[ i ].col_nm == "StudentID")
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                        if(  table[ j ].StudentID  >  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break;
                        }
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].StudentID  <  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].StudentID  !=  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                         if(  table[ j ].StudentID  >=  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                         if(  table[ j ].StudentID  <=  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm == "Phone"  )
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                         if(  table[ j ].Phone  >  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break;
                        }
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value )
                        {
                            dete = 1 ;
                            break;
                        }
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                        if(  table[ j ].Phone  <=  conditions[ i ].value )
                        {
                             dete = 1 ;
                             break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value , 0 ) ; // table後面    codition

                    if( a != string::npos )  // like  >>  要刪掉 >> break
                    {
                        dete = 1 ;
                        break;  //  not  like  // k = 1... 和 or 的logic
                    }

                }
                else if( conditions[ i ].col_nm == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value , 0 ) ;

                    if( a != string::npos )  // like  >>  要刪掉 >> break
                    {
                        dete = 1 ;
                        break;  //  not  like  // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value , 0 ) ;

                   if( a != string::npos )  // like  >>  要刪掉 >> break
                    {
                        dete = 1 ;
                        break;  //  not  like  // k = 1... 和 or 的logic
                    }

                }
            }
            if( k == 1 )
            {
                if(  conditions[ i ].col_nm_1 == "ID" )
                {
                    if(  conditions[ i ].optr_1 == ">"  )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "<" )
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "!=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == ">=")
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "<=" )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                }
                else if( conditions[ i ].col_nm_1 == "StudentID")
                {
                    if(  conditions[ i ].optr_1 == ">"  )
                    {
                        if(  table[ j ].StudentID  >  conditions[ i ].value_1 )
                        {
                           dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "<" )
                    {
                        if(  table[ j ].StudentID  <  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "!=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == ">=")
                    {
                         if(  table[ j ].StudentID  >=  conditions[ i ].value_1 )
                        {
                           dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "<=" )
                    {
                         if(  table[ j ].StudentID  <=  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_1 == "Phone"  )
                {
                    if(  conditions[ i ].optr_1 == ">"  )
                    {
                         if(  table[ j ].Phone  >  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "<" )
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value_1 )
                        {
                           dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == "=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "!=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_1 == ">=")
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value_1 )
                        {
                           dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_1 == "<=" )
                    {
                        if(  table[ j ].Phone  <=  conditions[ i ].value_1 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_1 == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  2 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 2  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value_1 , 0 ) ; // table後面    codition

                    if( a != string::npos ) //代表like >> 要刪掉
                    {
                        dete = 1 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_1 == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  2 ) ;
                    read_like_cmd( conditions , found ,  i , 2  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value_1 , 0 ) ;

                    if( a != string::npos ) //代表like >> 要刪掉
                    {
                        dete = 1 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_1 == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  2 ) ;
                    read_like_cmd( conditions , found ,  i , 2  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value_1 , 0 ) ;

                   if( a != string::npos ) //代表like >> 要刪掉
                    {
                        dete = 1 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
            }  //xddd
            if( k == 2 )
            {
                if(  conditions[ i ].col_nm_2 == "ID" )
                {
                    if(  conditions[ i ].optr_2 == ">"  )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "<" )
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "!=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == ">=")
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "<=" )
                    {
                        if(  table[ j ].ID  <= conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                }
                else if( conditions[ i ].col_nm_2 == "StudentID")
                {
                    if(  conditions[ i ].optr_2 == ">"  )
                    {
                        if(  table[ j ].StudentID  >  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "<" )
                    {
                        if(  table[ j ].StudentID  <  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "!=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == ">=")
                    {
                         if(  table[ j ].StudentID  >=  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "<=" )
                    {
                         if(  table[ j ].StudentID  <=  conditions[ i ].value_2 )
                        {
                           dete = 1 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_2 == "Phone"  )
                {
                    if(  conditions[ i ].optr_2 == ">"  )
                    {
                         if(  table[ j ].Phone  >  conditions[ i ].value_2 )
                        {
                           dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "<" )
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == "=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "!=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_2 == ">=")
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_2 == "<=" )
                    {
                        if(  table[ j ].Phone  <=  conditions[ i ].value_2 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_2 == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  3 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 3  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value_2 , 0 ) ; // table後面    codition

                    if( a != string::npos ) //代表like 藥膳調喔
                    {
                        dete = 1 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_2 == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  3 ) ;
                    read_like_cmd( conditions , found ,  i , 3  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value_2 , 0 ) ;

                    if( a != string::npos ) //代表like 藥膳調喔
                    {
                        dete = 1 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_2 == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  3 ) ;
                    read_like_cmd( conditions , found ,  i , 3  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value_2 , 0 ) ;

                    if( a != string::npos ) //代表like 藥膳調喔
                    {
                        dete = 1 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
            }
            if( k == 3 )
            {
                if(  conditions[ i ].col_nm_3 == "ID" )
                {
                    if(  conditions[ i ].optr_3 == ">"  )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "<" )
                    {
                        if(  table[ j ].ID  < conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value_3 )
                        {
                             dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "!=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == ">=")
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "<=" )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value_3 )
                        {
                             dete = 1 ;
                            break ;
                        }
                    }
                }
                else if( conditions[ i ].col_nm_3 == "StudentID")
                {
                    if(  conditions[ i ].optr_3 == ">"  )
                    {
                        if(  table[ j ].StudentID  >  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "<" )
                    {
                        if(  table[ j ].StudentID  <  conditions[ i ].value_3 )
                        {
                           dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "!=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == ">=")
                    {
                         if(  table[ j ].StudentID  >=  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "<=" )
                    {
                         if(  table[ j ].StudentID  <=  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_3 == "Phone"  )
                {
                    if(  conditions[ i ].optr_3 == ">"  )
                    {
                         if(  table[ j ].Phone  >  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "<" )
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == "=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "!=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if( conditions[ i ].optr_3 == ">=")
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                    else if(  conditions[ i ].optr_3 == "<=" )
                    {
                        if(  table[ j ].Phone  <=  conditions[ i ].value_3 )
                        {
                            dete = 1 ;
                            break ;
                        }
                    }
                }
                else if(  conditions[ i ].col_nm_3 == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  4 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 4 ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value_3 , 0 ) ; // table後面    codition

                    if( a != string::npos ) // 代表Like
                    {
                        dete = 1 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_3 == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  4 ) ;
                    read_like_cmd( conditions , found ,  i , 4  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value_3 , 0 ) ;

                    if( a != string::npos ) // 代表Like
                    {
                        dete = 1 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
                else if( conditions[ i ].col_nm_3 == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  4 ) ;
                    read_like_cmd( conditions , found ,  i , 4  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value_3 , 0 ) ;

                    if( a != string::npos ) // 代表Like
                    {
                        dete = 1 ;
                        break;  //  not  like >> 不用被刪掉 // k = 1... 和 or 的logic
                    }
                }
            }
        }
        else if( conditions[ i ].cnt == 0 ) // ONLY COL = 1 ; // only satisfy one solution
        {
                if(  conditions[ i ].col_nm == "ID" )
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                        if(  table[ j ].ID  >  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].ID  <  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                        if(  table[ j ].ID  ==  conditions[ i ].value )
                        {
                           dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].ID  !=  conditions[ i ].value )
                        {
                           dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                        if(  table[ j ].ID  >=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                        if(  table[ j ].ID  <=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                }
                else if( conditions[ i ].col_nm == "StudentID")
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                        if(  table[ j ].StudentID  >  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].StudentID  <  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                         if(  table[ j ].StudentID  ==  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                         if(  table[ j ].StudentID  !=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                         if(  table[ j ].StudentID  >=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                         if(  table[ j ].StudentID  <=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                }
                else if(  conditions[ i ].col_nm == "Phone"  )
                {
                    if(  conditions[ i ].optr == ">"  )
                    {
                         if(  table[ j ].Phone  >  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "<" )
                    {
                        if(  table[ j ].Phone  <  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == "=" )
                    {
                        if(  table[ j ].Phone  ==  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "!=" )
                    {
                        if(  table[ j ].Phone  !=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if( conditions[ i ].optr == ">=")
                    {
                        if(  table[ j ].Phone  >=  conditions[ i ].value )
                        {
                            dete = 1 ;
                        }
                        else
                        break ;
                    }
                    else if(  conditions[ i ].optr == "<=" )
                    {
                        if(  table[ j ].Phone  <=  conditions[ i ].value )
                        {
                             dete = 1 ;
                        }
                        else
                        break ;
                    }
                }
                else if(  conditions[ i ].col_nm == "Name" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;  // now 要改
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Name.find( conditions[ i ].lk_value , 0 ) ; // table後面    codition

                    if( a == string::npos )  break;  //  not  like  // k = 1... 和 or 的logic
                    else   dete = 1  ;
                }
                else if( conditions[ i ].col_nm == "Class" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Class.find( conditions[ i ].lk_value , 0 ) ;

                    if( a == string::npos )  break;  //  not  like
                    else   dete = 1  ; // like 要刪掉惹
                }
                else if( conditions[ i ].col_nm == "Email" )
                {
                    int found = read_percent( conditions ,  i ,  1 ) ;
                    read_like_cmd( conditions , found ,  i , 1  ) ;

                    int a = table[ j ].Email.find( conditions[ i ].lk_value , 0 ) ;

                    if( a == string::npos )  break;  //  not  like
                    else    dete = 1   ;
                }
        }
    }
    return dete ;
}


 void printStudent( struct student table[ ]  , struct condition conditions[ ] , int i , int j , int isValid )
 {
    if( isValid == 1 )
    {
         for( int k = 0 ; k < conditions[i].num_tab_col ; k++ )
         {
             if( k == 0 )
             {
                 if( conditions[ i ].tab_col_0 == "*" )
                 {
                    cout<<table[ j ].ID<<" "<<table[ j ].Name<<" "<<table[ j ].StudentID<<" ";
                    cout<<table[ j ].Class<<" "<<table[ j ].Email<<" "<<table[ j ].Phone;
                 }
                 else if( conditions[ i ].tab_col_0 == "ID" )
                 {
                     cout<<table[ j ].ID<<" ";
                 }
                 else if( conditions[ i ].tab_col_0 == "Name" )
                 {
                     cout<<table[ j ].Name<<" ";
                 }
                 else if( conditions[ i ].tab_col_0 == "StudentID" )
                 {
                     cout<<table[ j ].StudentID<<" ";
                 }
                 else if( conditions[ i ].tab_col_0 == "Class" )
                 {
                     cout<<table[ j ].Class<<" ";
                 }
                 else if( conditions[ i ].tab_col_0 == "Email" )
                 {
                     cout<<table[ j ].Email<<" ";
                 }
                 else if( conditions[ i ].tab_col_0 == "Phone" )
                 {
                     cout<<table[ j ].Phone<<" ";
                 }
                 if ( k == conditions[i].num_tab_col -1  ) cout<<"\n";

             }
             else if(  k == 1 )
             {
                if( conditions[ i ].tab_col_1 == "ID" )
                {
                     cout<<table[ j ].ID<<" ";
                }
                else if( conditions[ i ].tab_col_1 == "Name" )
                {
                     cout<<table[ j ].Name<<" ";
                }
                else if( conditions[ i ].tab_col_1 == "StudentID" )
                {
                     cout<<table[ j ].StudentID<<" ";
                }
                else if( conditions[ i ].tab_col_1 == "Class" )
                {
                     cout<<table[ j ].Class<<" ";
                }
                else if( conditions[ i ].tab_col_1 == "Email" )
                {
                     cout<<table[ j ].Email<<" ";
                }
                else if( conditions[ i ].tab_col_1 == "Phone" )
                {
                     cout<<table[ j ].Phone<<" ";
                }
                if ( k == conditions[i].num_tab_col -1  ) cout<<"\n";
             }
             else if( k == 2 )
             {
                if( conditions[ i ].tab_col_2 == "ID" )
                {
                     cout<<table[ j ].ID<<" ";
                }
                else if( conditions[ i ].tab_col_2 == "Name" )
                {
                     cout<<table[ j ].Name<<" ";
                }
                else if( conditions[ i ].tab_col_2 == "StudentID" )
                {
                     cout<<table[ j ].StudentID<<" ";
                }
                else if( conditions[ i ].tab_col_2 == "Class" )
                {
                     cout<<table[ j ].Class<<" ";
                }
                else if( conditions[ i ].tab_col_2 == "Email" )
                {
                     cout<<table[ j ].Email<<" ";
                }
                else if( conditions[ i ].tab_col_2 == "Phone" )
                {
                     cout<<table[ j ].Phone<<" ";
                }
                if ( k == conditions[i].num_tab_col -1  ) cout<<"\n";
             }
             else if( k == 3 )
             {
                if( conditions[ i ].tab_col_3 == "ID" )
                {
                     cout<<table[ j ].ID<<" ";
                }
                else if( conditions[ i ].tab_col_3 == "Name" )
                {
                     cout<<table[ j ].Name<<" ";
                }
                else if( conditions[ i ].tab_col_3 == "StudentID" )
                {
                     cout<<table[ j ].StudentID<<" ";
                }
                else if( conditions[ i ].tab_col_3 == "Class" )
                {
                     cout<<table[ j ].Class<<" ";
                }
                else if( conditions[ i ].tab_col_3 == "Email" )
                {
                     cout<<table[ j ].Email<<" ";
                }
                else if( conditions[ i ].tab_col_3 == "Phone" )
                {
                     cout<<table[ j ].Phone<<" ";
                }
                if ( k == conditions[i].num_tab_col -1  ) cout<<"\n";
             }
             else if( k == 4 )
             {
                 if( conditions[ i ].tab_col_4 == "ID" )
                {
                     cout<<table[ j ].ID<<" ";
                }
                else if( conditions[ i ].tab_col_4 == "Name" )
                {
                     cout<<table[ j ].Name<<" ";
                }
                else if( conditions[ i ].tab_col_4 == "StudentID" )
                {
                     cout<<table[ j ].StudentID<<" ";
                }
                else if( conditions[ i ].tab_col_4 == "Class" )
                {
                     cout<<table[ j ].Class<<" ";
                }
                else if( conditions[ i ].tab_col_4 == "Email" )
                {
                     cout<<table[ j ].Email<<" ";
                }
                else if( conditions[ i ].tab_col_4 == "Phone" )
                {
                     cout<<table[ j ].Phone<<" ";
                }
                if ( k == conditions[i].num_tab_col -1  ) cout<<"\n";
             }
             else if( k == 5 )
             {
                 if( conditions[ i ].tab_col_5 == "ID" )
                {
                     cout<<table[ j ].ID<<" ";
                }
                else if( conditions[ i ].tab_col_5 == "Name" )
                {
                     cout<<table[ j ].Name<<" ";
                }
                else if( conditions[ i ].tab_col_5 == "StudentID" )
                {
                     cout<<table[ j ].StudentID<<" ";
                }
                else if( conditions[ i ].tab_col_5 == "Class" )
                {
                     cout<<table[ j ].Class<<" ";
                }
                else if( conditions[ i ].tab_col_5 == "Email" )
                {
                     cout<<table[ j ].Email<<" ";
                }
                else if( conditions[ i ].tab_col_5 == "Phone" )
                {
                     cout<<table[ j ].Phone<<" ";
                }
                if ( k == conditions[i].num_tab_col -1  ) cout<<"\n";
             }
        }
        return ;
    }
    else
    return ;
 }

int main( )
{
    std::ios::sync_with_stdio(false) ;
    std::cin.tie(0) ;
    int N = 0 , M = 0 ;
    cin>>N>>M ;
    struct student table[N] ;
    for( int i = 0 ; i < N ; i++ )
    {
       cin>>table[ i ].ID>>table[ i ].Name>>table[ i ].StudentID;
       cin>>table[ i ].Class>>table[ i ].Email>>table[ i ].Phone;
    }
    cin.ignore();
    for( int i = 0 ; i <M ; i++ )
    {
        string a;
        getline( cin , a ) ;
        int cmmd = 0 , from = 0 ;
        int current = 0; //最初由 0 的位置開始找
        int next ;
        if( cmmd == 0 )
        {
            next = a.find_first_of(" ,;", current);
            string tmp = a.substr( current, next - current ) ;
            conditions[ i ].cmd = tmp ;
            current = next + 1; //下次由 next + 1 的位置開始找起
            cmmd = 1 ;
            //cout<< conditions[ i ].cmd << " " ;
        }
        if( conditions[ i ].cmd  == "SELECT")
        {
            while( 1 )
            {
                if( cmmd == 1 )
                {
                    if( conditions[ i ].num_tab_col  == 0  )
                    {
                        next = a.find_first_of(" ,;", current);
                        string tmp = a.substr( current, next - current ) ;
                        //cout<< tmp << " "  ;
                        conditions[ i ]. tab_col_0 = tmp ;
                        current = next + 2 ; //下次由 next + 1 的位置開始找起
                        conditions[ i ].num_tab_col++;
                        //cout<< conditions[ i ]. tab_col_0 << " 0 " ;
                        continue ;
                    }
                    else if (  conditions[ i ].num_tab_col  ==  1 )
                    {
                        next = a.find_first_of(" ,;", current);
                        string tmp = a.substr( current, next - current ) ;
                        //cout<< tmp << " "  ;
                        if( tmp == "ROM")
                        {
                            current = next + 1;
                            from = 1 ;
                            break ;
                            //printf("1\n") ;
                        }
                        else
                        {
                            conditions[ i ].tab_col_1  = tmp  ;
                            current = next + 2 ;  //下次由 next + 1 的位置開始找起
                            conditions[ i ].num_tab_col++;
                            //cout<< conditions[ i ]. tab_col_1 << " 1 " ;
                            continue ;
                        }
                    }
                    else if (  conditions[ i ].num_tab_col  ==  2 )
                    {
                        next = a.find_first_of(" ,;", current);
                        string tmp = a.substr( current, next - current ) ;
                        //cout<< tmp << " "  ;
                        if( tmp == "ROM")
                        {
                            current = next + 1;
                            from = 1 ;
                            break ;
                        }
                        conditions[ i ]. tab_col_2  = tmp  ;
                        current = next + 2;  //下次由 next + 1 的位置開始找起
                        conditions[ i ].num_tab_col++;
                        //cout<< conditions[ i ]. tab_col_2 << " 2 " ;
                        continue ;
                    }
                    else if (  conditions[ i ].num_tab_col  ==  3 )
                    {
                        next = a.find_first_of(" ,;", current);
                        string tmp = a.substr( current, next - current ) ;
                        if( tmp == "ROM" )
                        {
                            current = next + 1;
                            from = 1 ;
                            break ;
                        }
                        conditions[ i ]. tab_col_3  = tmp  ;
                        current = next + 2;  //下次由 next + 1 的位置開始找起
                        conditions[ i ].num_tab_col++;
                        //cout<< conditions[ i ]. tab_col_3 << " 3 " ;
                        continue ;
                    }
                    else if (  conditions[ i ].num_tab_col  ==  4 )
                    {

                        next = a.find_first_of(" ,;", current);
                        string tmp = a.substr( current, next - current ) ;
                        if( tmp == "ROM")
                        {
                            current = next + 1;
                            from = 1 ;
                            break ;
                        }
                        conditions[ i ]. tab_col_4  = tmp  ;
                        current = next + 2 ;  //下次由 next + 1 的位置開始找起
                        conditions[ i ].num_tab_col++;
                        //cout<< conditions[ i ]. tab_col_4 << " 4 " ;
                        continue ;
                    }
                    else if (  conditions[ i ].num_tab_col  ==  5 )
                    {
                        next = a.find_first_of(" ,;", current);
                        string tmp = a.substr( current, next - current ) ;
                        if( tmp == "ROM")
                        {
                            current = next + 1;
                            from = 1 ;
                            break ;
                        }
                        conditions[ i ]. tab_col_5  = tmp  ;
                        current = next + 2 ;  //下次由 next + 1 的位置開始找起
                        conditions[ i ].num_tab_col++;
                        //cout<< conditions[ i ].tab_col_5 << "  5 " ;
                        continue ;
                    }
                    else if (  conditions[ i ].num_tab_col  ==  6 )
                    {
                        next = a.find_first_of(" ,;", current);
                        string tmp = a.substr( current, next - current ) ;
                        current = next + 1;
                        from = 1 ;
                        conditions[ i ]. tab_col_6 = tmp ;
                        //cout<< conditions[ i ].tab_col_6 << "  6 " ;
                        break ;
                    }
                }
            }
            if( from ==  1 )
            {
                next = a.find_first_of(" ,;", current);
                current = next + 1;
                next = a.find_first_of(" ,;", current);
                string tmp = a.substr( current, next - current ) ;
                current = next + 1 ;
                if( tmp == "WHERE" )   from = 2 ;
                else if( tmp == "ORDER" ) from = 3 ;
                else from = 4 ; //select from tableA;
            }
            if( from ==  2 )
            {
                next = a.find_first_of(" ,;", current);
                string tmp_1 = a.substr( current, next - current ) ;
                current = next + 1 ;
                conditions[ i ].col_nm = tmp_1 ;  //  col_nm

                next = a.find_first_of(" ,;", current);
                string tmp_2 = a.substr( current, next - current ) ;
                current = next + 1 ;
                conditions[ i ].optr = tmp_2 ;

                if( conditions[ i ].optr == "LIKE" )
                {
                    current = current + 1 ; // pass "
                    next = a.find_first_of(" ,;\"", current);
                    string tmp_3 = a.substr( current, next - current ) ;
                    current = next + 2 ; // pass space
                    conditions[ i ].lk_value = tmp_3 ;
                }
                else
                {
                    next = a.find_first_of(" ,;", current);
                    string tmp_3 = a.substr( current, next - current ) ;
                    current = next + 1 ;
                    conditions[ i ].value = ston(  tmp_3  )  ;
                }

                conditions[ i ].num_col_nm++;

                next = a.find_first_of(" ,;", current) ;
                string tmp_4 = a.substr( current, next - current ) ;
                current = next + 1 ;
                //
                if( tmp_4 == "AND" )
                {
                    conditions[ i ].cnt = 2 ; // and
                    conditions[ i ].num_col_nm++;

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_5 = a.substr( current, next - current ) ;
                    current = next + 1 ;
                    conditions[ i ].col_nm_1 = tmp_5 ;

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_6 = a.substr( current, next - current ) ;
                    current = next + 1 ;
                    conditions[ i ].optr_1 = tmp_6 ;

                    if( conditions[ i ].optr_1 == "LIKE" )
                    {
                        current = current + 1 ; // pass "
                        next = a.find_first_of(" ,;\"", current);
                        string tmp_3 = a.substr( current, next - current ) ;
                        current = next + 2 ; // pass space
                        conditions[ i ].lk_value_1 = tmp_3 ;
                    }
                    else
                    {
                        next = a.find_first_of(" ,;", current);
                        string tmp_3 = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].value_1 = ston(  tmp_3  )  ;
                    }

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_8 = a.substr( current, next - current ) ;
                    current = next + 1 ;

                    if( tmp_8 == "AND")
                    {
                        conditions[ i ].num_col_nm++ ;
                        next = a.find_first_of(" ,;", current) ;
                        string tmp_9 = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].col_nm_2 = tmp_9 ;

                        next = a.find_first_of(" ,;", current) ;
                        string tmp_10 = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].optr_2 = tmp_10 ;

                        if( conditions[ i ].optr_2 == "LIKE" )
                        {
                            current = current + 1 ; // pass "
                            next = a.find_first_of(" ,;\"", current);
                            string tmp_3 = a.substr( current, next - current ) ;
                            current = next + 2 ; // pass space
                            conditions[ i ].lk_value_2 = tmp_3 ;
                        }
                        else
                        {
                            next = a.find_first_of(" ,;", current) ;
                            string tmp_11 = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].value_2 =ston(  tmp_11  )  ;
                        }

                        next = a.find_first_of(" ,;", current) ;
                        string tmp_12 = a.substr( current, next - current ) ;
                        current = next + 1 ;

                        if( tmp_12 == "AND" )
                        {
                            conditions[ i ].num_col_nm++ ;
                            next = a.find_first_of(" ,;", current) ;
                            string tmp_9 = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].col_nm_3 = tmp_9 ;

                            next = a.find_first_of(" ,;", current) ;
                            string tmp_10 = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].optr_3 = tmp_10 ;

                            if( conditions[ i ].optr_3 == "LIKE" )
                            {
                                current = current + 1 ; // pass "
                                next = a.find_first_of(" ,;\"", current);
                                string tmp_3 = a.substr( current, next - current ) ;
                                current = next + 2 ; // pass space
                                conditions[ i ].lk_value_3 = tmp_3 ;
                            }
                            else
                            {
                                next = a.find_first_of(" ,;", current) ;
                                string tmp_11 = a.substr( current, next - current ) ;
                                current = next + 1 ;
                                conditions[ i ].value_3 =ston(  tmp_11  )  ;
                            }

                            next = a.find_first_of(" ,;", current) ;
                            string tmp_16 = a.substr( current, next - current ) ; // order
                            current = next + 1 ;

                            if( tmp_16 == "ORDER" )
                            {
                                conditions[ i ].order = 1 ; //要排序

                                next = a.find_first_of(" ,;", current) ;
                                current = next + 1 ;  // BY

                                next = a.find_first_of(" ,;", current) ;
                                string tmp_A = a.substr( current, next - current ) ;
                                current = next + 1 ;
                                conditions[ i ].order_by_1 = tmp_A  ;

                                next = a.find_first_of(" ,;", current) ;
                                string tmp_B = a.substr( current, next - current ) ;
                                current = next + 1 ;
                                conditions[ i ].order_by_2 = tmp_B  ;
                            }
                        }
                        //v
                        else if( tmp_12 == "ORDER" )
                        {
                            conditions[ i ].order = 1 ; //要排序

                            next = a.find_first_of(" ,;", current) ;
                            current = next + 1 ;  // BY

                            next = a.find_first_of(" ,;", current) ;
                            string tmp_A = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].order_by_1 = tmp_A  ;

                            next = a.find_first_of(" ,;", current) ;
                            string tmp_B = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].order_by_2 = tmp_B  ;
                        }
                    }
                    //v
                    else if( tmp_8 == "ORDER" )
                    {
                        conditions[ i ].order = 1 ; //要排序

                        next = a.find_first_of(" ,;", current) ;
                        current = next + 1 ;  // BY

                        next = a.find_first_of(" ,;", current) ;
                        string tmp_A = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].order_by_1 = tmp_A  ;

                        next = a.find_first_of(" ,;", current) ;
                        string tmp_B = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].order_by_2 = tmp_B  ;
                    }
                }
                //
                else if(  tmp_4 == "OR"  )
                {
                    conditions[ i ].cnt = 1 ; // 1 for or
                    conditions[ i ].num_col_nm++;

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_5 = a.substr( current, next - current ) ;
                    current = next + 1 ;
                    conditions[ i ].col_nm_1 = tmp_5 ;

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_6 = a.substr( current, next - current ) ;
                    current = next + 1 ;
                    conditions[ i ].optr_1 = tmp_6 ;

                    if( conditions[ i ].optr_1 == "LIKE" )
                    {
                        current = current + 1 ; // pass "
                        next = a.find_first_of(" ,;\"", current);
                        string tmp_3 = a.substr( current, next - current ) ;
                        current = next + 2 ; // pass space
                        conditions[ i ].lk_value_1 = tmp_3 ;
                    }
                    else
                    {
                        next = a.find_first_of(" ,;", current);
                        string tmp_3 = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].value_1 = ston(  tmp_3  )  ;
                    }

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_8 = a.substr( current, next - current ) ;
                    current = next + 1 ;

                    if( tmp_8 == "OR")
                    {
                        conditions[ i ].num_col_nm++ ;
                        next = a.find_first_of(" ,;", current) ;
                        string tmp_9 = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].col_nm_2 = tmp_9 ;

                        next = a.find_first_of(" ,;", current) ;
                        string tmp_10 = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].optr_2 = tmp_10 ;

                        if( conditions[ i ].optr_2 == "LIKE" )
                        {
                            current = current + 1 ; // pass "
                            next = a.find_first_of(" ,;\"", current);
                            string tmp_3 = a.substr( current, next - current ) ;
                            current = next + 2 ; // pass space
                            conditions[ i ].lk_value_2 = tmp_3 ;
                        }
                        else
                        {
                            next = a.find_first_of(" ,;", current) ;
                            string tmp_11 = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].value_2 =ston(  tmp_11  )  ;
                        }

                        next = a.find_first_of(" ,;", current) ;
                        string tmp_12 = a.substr( current, next - current ) ;
                        current = next + 1 ;

                        if( tmp_12 == "OR" )
                        {
                            conditions[ i ].num_col_nm++ ;
                            next = a.find_first_of(" ,;", current) ;
                            string tmp_9 = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].col_nm_3 = tmp_9 ;

                            next = a.find_first_of(" ,;", current) ;
                            string tmp_10 = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].optr_3 = tmp_10 ;

                            if( conditions[ i ].optr_3 == "LIKE" )
                            {
                                current = current + 1 ; // pass "
                                next = a.find_first_of(" ,;\"", current);
                                string tmp_3 = a.substr( current, next - current ) ;
                                current = next + 2 ; // pass space
                                conditions[ i ].lk_value_3 = tmp_3 ;
                            }
                            else
                            {
                                next = a.find_first_of(" ,;", current) ;
                                string tmp_11 = a.substr( current, next - current ) ;
                                current = next + 1 ;
                                conditions[ i ].value_3 =ston(  tmp_11  )  ;
                            }

                            next = a.find_first_of(" ,;", current) ;
                            string tmp_16 = a.substr( current, next - current ) ; // order
                            current = next + 1 ;

                            if( tmp_16 == "ORDER" )
                            {
                                conditions[ i ].order = 1 ; //要排序

                                next = a.find_first_of(" ,;", current) ;
                                current = next + 1 ;  // BY

                                next = a.find_first_of(" ,;", current) ;
                                string tmp_A = a.substr( current, next - current ) ;
                                current = next + 1 ;
                                conditions[ i ].order_by_1 = tmp_A  ;

                                next = a.find_first_of(" ,;", current) ;
                                string tmp_B = a.substr( current, next - current ) ;
                                current = next + 1 ;
                                conditions[ i ].order_by_2 = tmp_B  ;
                            }
                        }
                        //v
                        else if( tmp_12 == "ORDER" )
                        {
                            conditions[ i ].order = 1 ; //要排序

                            next = a.find_first_of(" ,;", current) ;
                            current = next + 1 ;  // BY

                            next = a.find_first_of(" ,;", current) ;
                            string tmp_A = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].order_by_1 = tmp_A  ;

                            next = a.find_first_of(" ,;", current) ;
                            string tmp_B = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].order_by_2 = tmp_B  ;
                        }
                    }
                    //v
                    else if( tmp_8 == "ORDER" )
                    {
                        conditions[ i ].order = 1 ; //要排序

                        next = a.find_first_of(" ,;", current) ;
                        current = next + 1 ;  // BY

                        next = a.find_first_of(" ,;", current) ;
                        string tmp_A = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].order_by_1 = tmp_A  ;

                        next = a.find_first_of(" ,;", current) ;
                        string tmp_B = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].order_by_2 = tmp_B  ;
                    }
                }
                else if(  tmp_4 == "ORDER"  )
                {
                    conditions[ i ].order = 1 ; //要排序

                    next = a.find_first_of(" ,;", current) ;
                    current = next + 1 ;  // BY

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_A = a.substr( current, next - current ) ;
                    current = next + 1 ;
                    conditions[ i ].order_by_1 = tmp_A  ;

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_B = a.substr( current, next - current ) ;
                    current = next + 1 ;
                    conditions[ i ].order_by_2 = tmp_B  ;
                }
                //cout<<conditions[ i ].col_nm<<" "<<conditions[ i ].optr<<" "<<conditions[ i ].value;
            }
            if( from == 3 )
            {
                conditions[ i ].order = 1 ; //要排序

                next = a.find_first_of(" ,;", current) ;
                current = next + 1 ;  // BY

                next = a.find_first_of(" ,;", current) ;
                string tmp_A = a.substr( current, next - current ) ;
                current = next + 1 ;
                conditions[ i ].order_by_1 = tmp_A  ;

                next = a.find_first_of(" ,;", current) ;
                string tmp_B = a.substr( current, next - current ) ;
                current = next + 1 ;
                conditions[ i ].order_by_2 = tmp_B  ;
            }
        }
        else if( conditions[ i ].cmd == "DELETE" )
        {

            next = a.find_first_of(" ,;", current);
            current = next + 1; //下次由 next + 1 的位置開始找 // FROM

            next = a.find_first_of(" ,;", current);
            current = next + 1; //下次由 next + 1 的位置開始找起 //TABLEA

            next = a.find_first_of(" ,;", current);
            string tmp_0 = a.substr( current, next - current ) ;
            current = next + 1; //下次由 next + 1 的位置開始找起
            if( tmp_0 != "WHERE" ) continue ;


            conditions[ i ].num_col_nm++;
            next = a.find_first_of(" ,;", current);
            string tmp = a.substr( current, next - current ) ;
            conditions[ i ].col_nm = tmp ;
            current = next + 1; //下次由 next + 1 的位置開始找起

            next = a.find_first_of(" ,;", current);
            string tmp_1 = a.substr( current, next - current ) ;
            conditions[ i ].optr = tmp_1 ;
            current = next + 1;

            if( conditions[ i ].optr == "LIKE" )
            {
                current = current + 1 ; // pass "
                next = a.find_first_of(" ,;\"", current);
                string tmp_3 = a.substr( current, next - current ) ;
                current = next + 2 ; // pass space
                conditions[ i ].lk_value = tmp_3 ;
            }
            else
            {
                next = a.find_first_of(" ,;", current);
                string tmp_3 = a.substr( current, next - current ) ;
                current = next + 1 ;
                conditions[ i ].value = ston(  tmp_3  )  ;
            }

            next = a.find_first_of(" ,;", current) ;
            string tmp_3 = a.substr( current, next - current ) ;
            current = next + 1 ;

            if( tmp_3 == "AND" )
            {
                    conditions[ i ].cnt = 2 ; // 1 for or
                    conditions[ i ].num_col_nm++;

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_5 = a.substr( current, next - current ) ;
                    current = next + 1 ;
                    conditions[ i ].col_nm_1 = tmp_5 ;

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_6 = a.substr( current, next - current ) ;
                    current = next + 1 ;
                    conditions[ i ].optr_1 = tmp_6 ;

                    if( conditions[ i ].optr_1 == "LIKE" )
                    {
                        current = current + 1 ; // pass "
                        next = a.find_first_of(" ,;\"", current);
                        string tmp_3 = a.substr( current, next - current ) ;
                        current = next + 2 ; // pass space
                        conditions[ i ].lk_value_1 = tmp_3 ;
                    }
                    else
                    {
                        next = a.find_first_of(" ,;", current);
                        string tmp_3 = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].value_1 = ston(  tmp_3  )  ;
                    }

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_8 = a.substr( current, next - current ) ;
                    current = next + 1 ;

                    if( tmp_8 == "AND")
                    {
                        conditions[ i ].num_col_nm++ ;
                        next = a.find_first_of(" ,;", current) ;
                        string tmp_9 = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].col_nm_2 = tmp_9 ;

                        next = a.find_first_of(" ,;", current) ;
                        string tmp_10 = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].optr_2 = tmp_10 ;

                        if( conditions[ i ].optr_2 == "LIKE" )
                        {
                            current = current + 1 ; // pass "
                            next = a.find_first_of(" ,;\"", current);
                            string tmp_3 = a.substr( current, next - current ) ;
                            current = next + 2 ; // pass space
                            conditions[ i ].lk_value_2 = tmp_3 ;
                        }
                        else
                        {
                            next = a.find_first_of(" ,;", current);
                            string tmp_3 = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].value_2 = ston(  tmp_3  )  ;
                        }

                        next = a.find_first_of(" ,;", current) ;
                        string tmp_12 = a.substr( current, next - current ) ;
                        current = next + 1 ;

                        if( tmp_12 == "AND")
                        {
                            conditions[ i ].num_col_nm++ ;
                            next = a.find_first_of(" ,;", current) ;
                            string tmp_9 = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].col_nm_3 = tmp_9 ;

                            next = a.find_first_of(" ,;", current) ;
                            string tmp_10 = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].optr_3 = tmp_10 ;

                            if( conditions[ i ].optr_3 == "LIKE" )
                            {
                                current = current + 1 ; // pass "
                                next = a.find_first_of(" ,;\"", current);
                                string tmp_3 = a.substr( current, next - current ) ;
                                current = next + 2 ; // pass space
                                conditions[ i ].lk_value_3 = tmp_3 ;
                            }
                            else
                            {
                                next = a.find_first_of(" ,;", current);
                                string tmp_3 = a.substr( current, next - current ) ;
                                current = next + 1 ;
                                conditions[ i ].value_3 = ston(  tmp_3  )  ;
                            }
                        }
                    }
                }
                //
                else if( tmp_3 == "OR" )
                {
                    conditions[ i ].cnt = 1 ; // 1 for or
                    conditions[ i ].num_col_nm++;

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_5 = a.substr( current, next - current ) ;
                    current = next + 1 ;
                    conditions[ i ].col_nm_1 = tmp_5 ;

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_6 = a.substr( current, next - current ) ;
                    current = next + 1 ;
                    conditions[ i ].optr_1 = tmp_6 ;

                    if( conditions[ i ].optr_1 == "LIKE" )
                    {
                        current = current + 1 ; // pass "
                        next = a.find_first_of(" ,;\"", current);
                        string tmp_3 = a.substr( current, next - current ) ;
                        current = next + 2 ; // pass space
                        conditions[ i ].lk_value_1 = tmp_3 ;
                    }
                    else
                    {
                        next = a.find_first_of(" ,;", current);
                        string tmp_3 = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].value_1 = ston(  tmp_3  )  ;
                    }

                    next = a.find_first_of(" ,;", current) ;
                    string tmp_8 = a.substr( current, next - current ) ;
                    current = next + 1 ;

                    if( tmp_8 == "OR")
                    {
                        conditions[ i ].num_col_nm++ ;
                        next = a.find_first_of(" ,;", current) ;
                        string tmp_9 = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].col_nm_2 = tmp_9 ;

                        next = a.find_first_of(" ,;", current) ;
                        string tmp_10 = a.substr( current, next - current ) ;
                        current = next + 1 ;
                        conditions[ i ].optr_2 = tmp_10 ;

                        if( conditions[ i ].optr_2 == "LIKE" )
                        {
                            current = current + 1 ; // pass "
                            next = a.find_first_of(" ,;\"", current);
                            string tmp_3 = a.substr( current, next - current ) ;
                            current = next + 2 ; // pass space
                            conditions[ i ].lk_value_2 = tmp_3 ;
                        }
                        else
                        {
                            next = a.find_first_of(" ,;", current);
                            string tmp_3 = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].value_2 = ston(  tmp_3  )  ;
                        }

                        next = a.find_first_of(" ,;", current) ;
                        string tmp_12 = a.substr( current, next - current ) ;
                        current = next + 1 ;

                        if( tmp_12 == "OR")
                        {
                            conditions[ i ].num_col_nm++ ;
                            next = a.find_first_of(" ,;", current) ;
                            string tmp_9 = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].col_nm_3 = tmp_9 ;

                            next = a.find_first_of(" ,;", current) ;
                            string tmp_10 = a.substr( current, next - current ) ;
                            current = next + 1 ;
                            conditions[ i ].optr_3 = tmp_10 ;

                            if( conditions[ i ].optr_3 == "LIKE" )
                            {
                                current = current + 1 ; // pass "
                                next = a.find_first_of(" ,;\"", current);
                                string tmp_3 = a.substr( current, next - current ) ;
                                current = next + 2 ; // pass space
                                conditions[ i ].lk_value_3 = tmp_3 ;
                            }
                            else
                            {
                                next = a.find_first_of(" ,;", current);
                                string tmp_3 = a.substr( current, next - current ) ;
                                current = next + 1 ;
                                conditions[ i ].value_3 = ston(  tmp_3  )  ;
                            }
                        }
                    }
                }
            }
    }

    /*for( int i = 0 ; i < M ; i++ )
    {
        if( conditions[ i ].num_col_nm > 4 ) return 0 ;
        else printf("%d\n",conditions[ i ].num_col_nm) ;
    } */

    /*struct student cop[ 20 ];

    for( int i = 0 ; i<M; i++ )
    {
        cout<<conditions[ i ].col_nm<<" "<<conditions[ i ].optr<<" ";
        if( conditions[ i ].optr == "LIKE")
        {
            cout<<conditions[ i ].lk_value<<"\n";
        }
        else  cout<<conditions[ i ].value<<"\n";
        cout<<conditions[ i ].col_nm_1<<" "<<conditions[ i ].optr_1<<" ";
        if( conditions[ i ].optr_1 == "LIKE")
        {
            cout<<conditions[ i ].lk_value_1<<"\n";
        }
        else  cout<<conditions[ i ].value_1<<"\n";
        cout<<conditions[ i ].col_nm_2<<" "<<conditions[ i ].optr_2<<" ";
        if( conditions[ i ].optr_2 == "LIKE")
        {
            cout<<conditions[ i ].lk_value_2<<"\n";
        }
        else  cout<<conditions[ i ].value_2<<"\n";
        cout<<conditions[ i ].col_nm_3<<" "<<conditions[ i ].optr_3<<" ";
         if( conditions[ i ].optr_3 == "LIKE")
        {
            cout<<conditions[ i ].lk_value_3<<"\n";
        }
        else  cout<<conditions[ i ].value_3<<"\n";
        cout<<conditions[ i ].order_by_1<<" "<<conditions[ i ].order_by_2<<" "<<conditions[ i ].num_col_nm<<"\n";
    } */


     for( int i = 0 ; i < M ; i++ ) // cmd
    {
        if( conditions[ i ].order  ==  0  ) //不用排序
        {
            for( int j = 0 ; j <N ; j++ ) // data is valid
            {
                if(  conditions[ i ].cmd == "DELETE" )
                {
                    if( table[ j ].isValid == 2 )
                    {
                        continue ;
                    }
                    else
                    {
                        dele_cmd(  table , conditions , i , j  ) ;
                    }
                }
                else if( conditions[ i ].cmd == "SELECT" )
                {
                    if(  table[ j ].isValid == 2 )   // 代表被刪掉了
                    {
                        continue ;
                    }
                    else if( table[ j ].isValid == 0 )  // 代表還沒被刪除
                    {
                        int isValid =  isStudentValid( table , conditions , i , j  ) ;
                        printStudent( table  , conditions , i ,  j ,  isValid ) ;
                    }
                }
            }
        }
        else if( conditions[ i ].order  ==  1 ) //要排序  必定為 select cmd
        {
            struct student cpy[ 1000 ];
            int  index_cpy = 0 ;
            for( int j = 0 ; j < N ; j++ )
            {
                if( table[ j ].isValid == 2) //被刪掉了
                {
                    continue ;
                }
                else
                {
                    int isValid = isStudentValid( table , conditions , i , j  ) ;
                    if( isValid == 1 )
                    {
                        cpy[  index_cpy  ]  = table[ j ]  ;
                        index_cpy ++ ;
                    }
                }
            }
            if( index_cpy != 0 )
            {
                CopySort(  cpy , conditions , i ,  index_cpy  ) ;
                for( int k = 0 ; k < index_cpy ; k++ )
                {
                    printStudent( cpy  , conditions , i ,  k ,  1 ) ;
                }
            }
            else
                continue;
        }
    }


    return 0 ;
}
