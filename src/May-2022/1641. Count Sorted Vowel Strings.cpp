class Solution {
        if count == 1 {
            return 5
        }
        var refArr = [5,4,3,2,1]
        var counter = 2 
        while counter < count {
            for i in 0...refArr.count - 2 {
                   refArr[refArr.count - 2 - i] = refArr[refArr.count - 2 - i] + refArr[refArr.count - 1 - i]
            }
            counter += 1
        }
        return refArr.reduce(0){$0+$1}
    }
}
