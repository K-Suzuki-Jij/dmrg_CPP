#include <cmath>
#include "SML.hpp"
#include "Model_1D_TAKLM.hpp"

void Model_1D_TAKLM::Get_SzC_1_On(CRS &M, double coeef) {
   
   ///////////////////////////////////////
   // # <->  [Cherge  ] -- (N,  2*sz)
   // 0 <->  [        ] -- (0,  0   )
   // 1 <->  [up      ] -- (1,  1   )
   // 2 <->  [down    ] -- (1, -1   )
   // 3 <->  [up&down ] -- (2,  0   )
   ///////////////////////////////////////
   
   Check_Parameters();
   
   Free_CRS(M);
   M.row_dim = Find_Dim_Onsite();
   M.col_dim = Find_Dim_Onsite();
   
   M.Row.push_back(0);
   
   for (int row_ele_1 = 0; row_ele_1 < dim_ele; row_ele_1++) {
      for (int row_ele_2 = 0; row_ele_2 < dim_ele; row_ele_2++) {
         for (int row_lspin = 0; row_lspin < dim_lspin; row_lspin++) {
            for (int col_ele_1 = 0; col_ele_1 < dim_ele; col_ele_1++) {
               for (int col_ele_2 = 0; col_ele_2 < dim_ele; col_ele_2++) {
                  for (int col_lspin = 0; col_lspin < dim_lspin; col_lspin++) {
                     int a = row_ele_1;
                     int b = col_ele_1;
                     double val = (1.5 - b)*Delta_Function(a, b)*coeef;
                     
                     if (row_ele_1 == 0 || row_ele_1 == 3 || col_ele_1 == 0 || col_ele_1 == 3) {
                        val = 0.0;
                     }
                     
                     if (std::abs(val) > 0.0 && row_lspin == col_lspin && row_ele_2 == col_ele_2) {
                        M.Val.push_back(val);
                        M.Col.push_back(col_ele_1*dim_ele*dim_lspin + col_ele_2*dim_lspin + col_lspin);
                     }
                     
                  }
               }
            }
            M.Row.push_back(M.Col.size());
         }
      }
   }
      
   Check_Symmetric_Matrix(M, zero_precision);

}
