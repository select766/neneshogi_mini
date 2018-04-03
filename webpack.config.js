const path = require('path');

module.exports = {
    mode: 'development',
    entry: './src/index.ts',
    module: {
        rules: [
            {
                test: /\.ts$/,
                use: 'ts-loader'
            }
        ]
    },
    resolve: {
        extensions: [
            '.ts'
        ]
    },
    output: {
        filename: 'bundle.js',
        path: path.join(__dirname, 'public/js')
    }
};
