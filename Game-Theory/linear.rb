#nxm'lik oyunlar için iterasyon yöntemi

require 'matrix'

def find_min(a)
  min=a[0]
  1. step a.length()-1 do |i|
    if(min> a[i])
      min=a[i]
    end
  end
  return min
end

def find_max(a)
  max=a[0]
  1.step a.length()-1 do |i|
    if(max<a[i])
      max=a[i]
    end
  end
  return max
end

def iteration(a,n)
  vmin=0
  vmax=0
  col_c=a.column_count
  row_c=a.row_count
  x=Array.new(row_c,0)
  y=Array.new(col_c,0)
  probabilitiesA=Array.new(row_c,0)
  probabilitiesB=Array.new(col_c,0)

  j=0
  1.step n do |i|
    0.step col_c-1 do |k|
      y[k]=y[k]+a[j,k]
    end
    min=find_min(y)
    j=y.index(min)
    probabilitiesB[j]=probabilitiesB[j]+1

    0.step row_c-1 do |k|
      x[k]=x[k]+a[k,j]
    end
    max=find_max(x)
    j=x.index(max)
    probabilitiesA[j]=probabilitiesA[j]+1
  end
  print x,"\n"
  print y,"\n"

  print "\nProbabilities of A:"
  0.step row_c-1 do |k|
    f=1.0*probabilitiesA[k]/n
    print f, " "
  end
  print "\n\nProbabilities of B: "
  0.step col_c-1 do |k|
    f=1.0*probabilitiesB[k]/n
    print f," "
  end

  vmin= 1.0*find_min(y)/n
  vmax= 1.0*find_max(x)/n
  print "\n\nvmin=", vmin, "vmax=",vmax
end
a=Matrix[[9,4,2],[3,6,8],[5,7,2]]
iteration(a,10000)
