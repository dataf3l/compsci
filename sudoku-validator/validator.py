class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        output = []
        if len(matrix) == 0:
            return []
        
        ouput_row_count = len(matrix[0])
        x = 0
        while x < ouput_row_count:
            output.append( [matrix[p][x] for p in range(0,len(matrix))] )
            x += 1
        return output

    def is_valid(self, row):
        row = [r for r in row if r != '.']
        return len(set(row)) == len(row)

    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # validate rows
        for row in board:
            if self.is_valid(row) is False:
                return False
        
        board = self.transpose(board)

        # validate rows
        for row in board:
            if self.is_valid(row) is False:
                return False
        
        chunk = 0
        x_base_offset = [0,3,6] * 3
        y_base_offset = [0,0,0,3,3,3,6,6,6]
        while chunk < 9:
            elements = []
            x = 0
            while x < 3:
                y = 0
                while y < 3:
                    x_offset = x_base_offset[chunk]
                    y_offset = y_base_offset[chunk]
                    elements.append( board[x_offset + x][y_offset + y] )
                    y +=1

                x+=1
            if self.is_valid(elements) is False:
                return False
            chunk +=1
        
        # blocks.
        return True

        

