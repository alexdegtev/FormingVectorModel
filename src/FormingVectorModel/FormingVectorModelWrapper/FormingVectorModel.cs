using System.Diagnostics;

namespace FormingVectorModelWrapper
{
    public class FormingVectorModel
    {
        public static void LaunchExe(string query)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo
            {
                FileName = @"FormingVectorModel.exe", 
                Arguments = query
                //WindowStyle = ProcessWindowStyle.Hidden
            };

            try
            {
                using (Process process = Process.Start(startInfo))
                {
                    process.WaitForExit();
                }
            }
            catch
            {
                
            }
        }
    }
}
